import re

# String do path extraído do SVG
path_data = "M194.5 34.5L192.5 29.5L161 4L162.5 7.5L185 29L190 32.5L194.5 34.5Z"


# Lista para armazenar os pontos
points = []

# Posição inicial
current_x = 0
current_y = 0

# Função para adicionar ponto à lista
def add_point(x, y):
    points.append((x, y))

# Regex para capturar os comandos M, L, H, V e seus valores
commands = re.findall(r'[MLHVZmlhvz]|-?\d*\.?\d+', path_data)

# Percorrer os comandos e extrair os pontos
i = 0
while i < len(commands):
    command = commands[i]
    
    if command == 'M' or command == 'L':  # Move to or Line to
        current_x = float(commands[i + 1])
        current_y = float(commands[i + 2])
        add_point(current_x, current_y)
        i += 3
    elif command == 'H':  # Horizontal line
        current_x = float(commands[i + 1])
        add_point(current_x, current_y)
        i += 2
    elif command == 'V':  # Vertical line
        current_y = float(commands[i + 1])
        add_point(current_x, current_y)
        i += 2
    elif command == 'Z':  # Close path
        # In most cases, you would connect the last point to the first point
        if points:
            add_point(points[0][0], points[0][1])
        i += 1
    else:  # Handle other cases like numbers
        i += 1

# Exibir os pontos
for point in points:
    print(f"applyRampTransform(Point(xStart + {int(point[0])}, yStart + {int(point[1])}), this->degrees),")