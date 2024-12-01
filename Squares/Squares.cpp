#include <stdio.h>
#include <stdlib.h>

// Function to display a rectangle
void print_rectangle(int width, int height, int color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("\033[4%dm  \033[0m", color);
        }
        printf("\n");
    }
}

// Main program
int main() {
    int width, height;

    printf("Enter the width of the rectangle: ");
    scanf_s("%d", &width);
    printf("Enter the height of the rectangle: ");
    scanf_s("%d", &height);

    int num_squares = 0;
    int current_width = width;
    int current_height = height;

    printf("Original rectangle (%dx%d):\n", width, height);
    print_rectangle(width, height, 7); // White color
    printf("\n");

    printf("Cutting process:\n");
    while (current_width > 0 && current_height > 0) {
        int side = (current_width < current_height) ? current_width : current_height; // Current square size
        num_squares++;

        // Display the square
        printf("Square %d (%dx%d):\n", num_squares, side, side);
        print_rectangle(side, side, num_squares % 6 + 1); // Cycle through colors
        printf("\n");

        // Update rectangle dimensions
        if (current_width <= current_height) {
            current_height -= side;
        }
        else {
            current_width -= side;
        }
    }

    printf("Total number of squares: %d\n", num_squares);

    return 0;
}
