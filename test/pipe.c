#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

extern char **environ; // 環境変数を取得

int main(void) {
    int pipefd[2];
    pid_t pid;

    char *cat_args[] = {"/bin/cat", "infile", NULL};
    char *grep_args[] = {"/usr/bin/grep", "hello42!", NULL};

	// pipeは失敗時に-1を返す
    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

// 現在のプロセスを複製し、親プロセスと子プロセスの 2 つを作成します。
// 新しく作成された子プロセスのプロセス ID（pid）を返します（通常、pid > 0）。
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // 子プロセス (grep)
        dup2(pipefd[0], 0); // パイプの読み取り側を標準入力に
        close(pipefd[1]);   // 書き込み側は不要
        close(pipefd[0]);   // 自分の側も閉じる
        execve("/usr/bin/grep", grep_args, environ);
        perror("execve grep");
        return 1;
    } else {
        // 親プロセス (cat)
        dup2(pipefd[1], 1); // パイプの書き込み側を標準出力に
        close(pipefd[0]);   // 読み取り側は不要
        close(pipefd[1]);   // 自分の側も閉じる
        execve("/bin/cat", cat_args, environ);
        perror("execve cat");
        return 1;
    }

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, NULL, 0); // 子プロセスの終了を待つ
    return 0;
}
