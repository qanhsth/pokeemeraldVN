from PIL import Image

input_file = "back_button.png"
output_file = "back_button_fixed.png"

img = Image.open(input_file).convert("P")

# New palette index -> original palette index
mapping = {
    0: 0,
    1: 3,
    2: 4,    # #C5BDB4
    3: 2,    # #393939
    4: 1,
    5: 13,
    6: 12,
    7: 14,
}

# Remap pixels
pixels = [mapping[p] for p in img.getdata()]
img.putdata(pixels)

# EXACT original 16-color palette
palette = [
    106,156,213, #6A9CD5 srgb(106,156,213)
    255,255,255, #FFFFFF white
    57,57,57, #393939 srgb(57,57,57)
    139,139,131, #8B8B83 srgb(139,139,131)
    197,189,180, #C5BDB4 srgb(197,189,180)
    230,222,213, #E6DED5 srgb(230,222,213)
    74,115,139, #4A738B srgb(74,115,139)
    123,172,197, #7BACC5 srgb(123,172,197)
    172,115,74, #AC734A srgb(172,115,74)
    213,156,115, #D59C73 srgb(213,156,115)
    98,156,57, #629C39 srgb(98,156,57)
    148,189,106, #94BD6A srgb(148,189,106)
    189,164,32, #BDA420 srgb(189,164,32)
    230,222,90, #E6DE5A srgb(230,222,90)
    57,57,57, #393939 srgb(57,57,57)
    57,57,57, #393939 srgb(57,57,57)
]

img.putpalette(palette)

# Save
img.save(output_file)

print("Saved:", output_file)
