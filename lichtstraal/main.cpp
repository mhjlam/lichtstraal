#include "bitmap_image.hpp"

int main()
{
	int w = 100;
	int h = 100;

	bitmap_image bitmap(w, h);

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			bitmap.set_pixel(x, y,
				palette_colormap[(x + y) % 50].red,
				palette_colormap[(x + y) % 50].green,
				palette_colormap[(x + y) % 50].blue);
		}
	}

	bitmap.save_image("output.bmp");

	return 0;
}
