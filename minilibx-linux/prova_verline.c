#include "mlx.h"

typedef struct {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} Image;

// Function to draw a vertical line on an image
void verLine(Image *img, int x, int y1, int y2, int color) {
    int y;
    
    for (y = y1; y <= y2; y++) {
        if (x >= 0 && x < img->line_length / (img->bits_per_pixel / 8) && y >= 0 && y < img->line_length / img->line_length) {
            int pixel_offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
            *(int *)(img->addr + pixel_offset) = color;
        }
    }
}

int main() {
    // Initialize MiniLibX and create a window
    
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Vertical Line Example");
    
    // Create an image
    Image img;
    img.img_ptr = mlx_new_image(mlx_ptr, 800, 600);
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    // Draw a vertical line on the image
    int line_color = 0xFF0000; // Red color in RGB format (0xRRGGBB)
    verLine(&img, 400, 100, 500, line_color);
    
    // Display the image on the window
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
    
    // Enter the MiniLibX event loop
    mlx_loop(mlx_ptr);
    
    return 0;
}
