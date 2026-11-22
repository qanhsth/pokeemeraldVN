from PIL import Image

input_file = "menu.png"
original_file = "menu_org.png"
output_file = "menu_fixed.png"

# Load images as indexed PNGs
img = Image.open(input_file).convert("P")
org = Image.open(original_file).convert("P")

# New palette index -> original palette index
mapping = {
    0:  0,   # (123,131,0)   -> (123,131,0)
    1: 12,   # (49,213,74)   -> (49,213,74)
    2:  1,   # white         -> white
    3: 10,   # (238,246,57)  -> (238,246,57)
    4:  6,   # (41,57,65)    -> (41,57,65)
    5:  5,   # (98,98,115)   -> (98,98,115)
    6:  8,   # (0,0,41)      -> (0,0,41)
    7: 14,   # (189,156,90)  -> (189,156,90)
    8: 13,   # (24,131,32)   -> (24,131,32)
    9:  3,   # (189,189,189) -> (189,189,189)
    10: 15,  # black         -> black
    11: 7,   # (41,57,106)   -> (41,57,106)
    12: 4,   # (164,164,164) -> (164,164,164)
    13: 11,  # (255,0,189)   -> (255,0,189)
    14: 2,   # (197,32,32)   -> (197,32,32)
}

# Remap pixel indices
pixels = list(img.getdata())
fixed_pixels = []

for index in pixels:
    if index not in mapping:
        raise ValueError(f"Missing mapping for palette index {index}")
    fixed_pixels.append(mapping[index])

# Create output and apply original palette
output = Image.new("P", img.size)
output.putdata(fixed_pixels)
output.putpalette(org.getpalette())

# Preserve transparency if the source image has it
if "transparency" in img.info:
    output.info["transparency"] = img.info["transparency"]

output.save(output_file, optimize=False)

print(f"Saved corrected image: {output_file}")
