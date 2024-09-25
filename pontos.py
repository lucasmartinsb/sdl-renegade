import re

# String do path extraído do SVG
path_data = "M16.5 89H20L29.5 64.5L61.5 65.5L74 92.5L184.5 93.5L194 65.5H232.5L240.5 92H248.5L256.5 86.5V83.5L265 71V67L263.5 65V59.5L259 56L257.5 55V47L256 44L246 37.5L227.5 33L192 29.5L161 4L125.5 1.5L74 0.5L28 3L17 4.5L13.5 4L12 6L16.5 9L9 28.5L7 31L6 35V47H5V52L3.5 63.5L1 65.5L2 77.5L10.5 87L16.5 89Z"


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
    print(f"applyRampTransform(Point(this->start.getX() + {int(point[0])}, yAssoalho + {int(point[1])}), this->degrees),")