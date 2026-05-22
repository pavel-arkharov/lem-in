import sys
import random

def generate_grid_map(width, height, ants):
    print(ants)
    
    # Rooms
    for y in range(height):
        for x in range(width):
            name = f"{x}_{y}"
            if x == 0 and y == 0:
                print("##start")
            elif x == width - 1 and y == height - 1:
                print("##end")
            print(f"{name} {x*10} {y*10}")
            
    # Links
    for y in range(height):
        for x in range(width):
            # Horizontal
            if x < width - 1:
                print(f"{x}_{y}-{x+1}_{y}")
            # Vertical
            if y < height - 1:
                print(f"{x}_{y}-{x}_{y+1}")

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Usage: python3 map_gen.py <width> <height> <ants>")
        sys.exit(1)
    
    width = int(sys.argv[1])
    height = int(sys.argv[2])
    ants = int(sys.argv[3])
    generate_grid_map(width, height, ants)
