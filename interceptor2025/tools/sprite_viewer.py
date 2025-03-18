import re
import sys
from collections import OrderedDict
import pygame

# Constants
PIXEL_SIZE = 16  # Size of each pixel in the Pygame window
SPRITE_WIDTH = 16
SPRITE_HEIGHT = 16

def parse_sprite_file(file_path):
    sprite_dict = OrderedDict()
    current_key = None
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            match = re.match(r'PUBLIC (.+_col[12])', line)
            if match:
                key_name = match.group(1)
                sprite_dict[key_name] = []  # Initialize empty array for each key

        for line in lines:
            if current_key and len(sprite_dict[current_key]) < 16:
                # Extract only numbers from the line, flatten them, and slice the last 8 symbols
                numbers = re.findall(r'\d+', line)
                flat_numbers = ''.join(numbers)[-8:]
                sprite_dict[current_key].append(flat_numbers)
            col_match = re.match(r'\.(.+_col[12])', line)
            if col_match:
                current_key = col_match.group(1)

    return sprite_dict

def print_sprite_dict(sprite_dict):
    for key, values in sprite_dict.items():
        print(f"{key}:")
        for value in values:
            print(value)

def draw_column(window, values, column_index):
    for y, line in enumerate(values):
        for x, char in enumerate(line):
            color = (255, 0, 0) if char == '1' else (0, 0, 0)
            pygame.draw.rect(window, color, ((column_index * 8 * PIXEL_SIZE) + x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE))

# Function to draw the sprite based on the parsed data
def draw_sprite(sprite_dict):
    # Initialize Pygame
    pygame.init()
    window_size = (SPRITE_WIDTH * PIXEL_SIZE, SPRITE_HEIGHT * PIXEL_SIZE)
    window = pygame.display.set_mode(window_size)
    pygame.display.set_caption("ZX Spectrum Sprite Viewer")

    # Draw only the first two columns
    keys = list(sprite_dict.keys())
    draw_column(window, sprite_dict[keys[0]], 0)
    draw_column(window, sprite_dict[keys[1]], 1)

    pygame.display.flip()  # Update the display

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

    pygame.quit()

# Parse sprite file from command-line argument
if len(sys.argv) < 2:
    print("Usage: python sprite_viewer.py <sprite_file>")
    sys.exit(1)

sprite_file_path = sys.argv[1]

# Parse the ASM file
sprite_data = parse_sprite_file(sprite_file_path)
print_sprite_dict(sprite_data)
draw_sprite(sprite_data)