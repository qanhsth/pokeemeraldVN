from PIL import Image

input_file = "latin_small_narrow.png"
output_file = "latin_small_narrow_fixed.png"

img = Image.open(input_file).convert("P")

# Current palette index -> original palette index
mapping = {
    0: 0,
    1: 3,
    2: 1,
    3: 2,
}

pixels = list(img.getdata())
pixels = [mapping[p] for p in pixels]

img.putdata(pixels)

# Original palette
palette = [
    144, 200, 255,  # 0 = blue
    56, 56, 56,     # 1 = dark gray
    216, 216, 216,  # 2 = light gray
    255, 255, 255,  # 3 = white
]

img.putpalette(palette)
img.save(output_file)

print("Saved:", output_file)
