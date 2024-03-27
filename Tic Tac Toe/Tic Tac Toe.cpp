#include <raylib.h>

const int screenWidth = 600;
const int screenHeight = 600;
const int cellSize = screenWidth / 3;
const int buttonWidth = 100;
const int buttonHeight = 30;

int main()
{
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
            DrawLine(cellSize * (i + 1), 0, cellSize * (i + 1), screenHeight, BLACK);
            DrawLine(0, cellSize * (i + 1), screenWidth, cellSize * (i + 1), BLACK);
        }

        // Draw X's and O's
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                {
                    DrawText("X", cellSize * j + cellSize / 2 - 20, cellSize * i + cellSize / 2 - 4, 40, LIGHTGRAY);
                }
                else if (board[i][j] == 'O')
                {
                    DrawText("O", cellSize * j + cellSize / 2 - 20, cellSize * i + cellSize / 2 - 4, 40, RED);
                }
            }
        }

        // Handle player input and game logic
        if (!gameOver)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                int cellX = GetMouseX() / cellSize;
                int cellY = GetMouseY() / cellSize;

                if (board[cellY][cellX] == '\0')
                {
                    board[cellY][cellX] = currentPlayer == 1 ? 'X' : 'O';
                    currentPlayer = currentPlayer == 1 ? 2 : 1;

                    // Check for winner or tie
                    if (checkWinner(board) || checkTie(board))
                    {
                        gameOver = true;
                    }
                }
            }
        }

        // Draw text for current player
        DrawText("Player ", 10, 10, 20, BLACK);
        DrawText(std::to_string(currentPlayer), 40, 10, 20, currentPlayer == 1 ? LIGHTGRAY : RED);
        DrawText("'s turn!", 60, 10, 20, BLACK);

        // Draw reset button
        if (isButtonClicked(screenWidth - buttonWidth - 10, screenHeight - buttonHeight - 10, buttonWidth, buttonHeight))
        {
            gameOver = false;
            currentPlayer = 1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    board[i][j] = '\0';
                }
            }
        }

        DrawRectangle(screenWidth - buttonWidth - 10, screenHeight - buttonHeight - 10, buttonWidth, buttonHeight, LIGHTGRAY);
        DrawText("Reset", screenWidth - buttonWidth - 10 + (buttonWidth - MeasureText("Reset", 20) / 2), screenHeight - buttonHeight - 10 + (buttonHeight - 20) / 2, 20, BLACK);

        // Display winner or tie message (if applicable)
        if (gameOver)
        {
            if (checkWinner(board))
            {
                DrawText("Player " + std::to_string(currentPlayer - 1) + " wins!", screenWidth / 2 - 90, screenHeight / 2, 20, BLACK);
            }
            else
            {
                DrawText("It's a Tie!", screenWidth / 2 - 40, screenHeight /
            }

            EndDrawing();
        }

        CloseWindow();

        return 0;
    }

    bool checkWinner(char board[3][3]);
    {
        // ... existing code for checking rows and diagonals

        return true; // Replace with the actual winner check logic
    }

    bool checkTie(char board[3][3])
    {
        // Check for all cells filled (no empty cell)
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '\0')
                {
                    return false; // Empty cell found, not a tie
                }
            }
        }

        return true;
    }

    bool isButtonClicked(int x, int y, int width, int height)
    {
        return IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
            GetMouseX() >= x && GetMouseX() <= x + width &&
            GetMouseY() >= y && GetMouseY() <= y + height;
    }
