#include <raylib.h>

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe");

    bool gameOver = false;
    char board[3][3] = {};  // Initialize empty board
    int currentPlayer = 1; // Player 1 starts

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw grid lines
        for (int i = 0; i < 2; i++)
        {
            DrawLine(screenWidth / 3 * (i + 1), 0, screenWidth / 3 * (i + 1), screenHeight, BLACK);
            DrawLine(0, screenHeight / 3 * (i + 1), screenWidth, screenHeight / 3 * (i + 1), BLACK);
        }

        // Draw X's and O's
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                {
                    DrawText("X", screenWidth / 6 + i * screenWidth / 3 - 16, screenHeight / 6 + j * screenHeight / 3 - 4, 40, LIGHTGRAY);
                }
                else if (board[i][j] == 'O')
                {
                    DrawText("O", screenWidth / 6 + i * screenWidth / 3 - 16, screenHeight / 6 + j * screenHeight / 3 - 4, 40, RED);
                }
            }
        }

        // Handle player input and game logic
        if (!gameOver)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                int cellX = GetMouseX() / (screenWidth / 3);
                int cellY = GetMouseY() / (screenHeight / 3);

                if (board[cellY][cellX] == '\0')
                {
                    board[cellY][cellX] = currentPlayer == 1 ? 'X' : 'O';
                    currentPlayer = currentPlayer == 1 ? 2 : 1;

                    // Check for winner
                    if (checkWinner(board))
                    {
                        gameOver = true;
                        DrawText("Player " + std::to_string(currentPlayer - 1) + " wins!", screenWidth / 2 - 90, screenHeight / 2, 20, BLACK);
                    }
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

bool checkWinner(char board[3][3])
{
    // Check rows, columns, and diagonals for a winner
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '\0')
        {
            return true;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '\0')
        {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '\0')
    {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '\0')
    {
        return true;

    }


}