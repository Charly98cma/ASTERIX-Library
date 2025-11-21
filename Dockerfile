FROM debian:stable-slim

# Instalar herramientas de compilación y CppUTest
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    pkg-config \
    cmake \
    git \
    cpputest \
    && rm -rf /var/lib/apt/lists/*

# Add custom user for compilation process
RUN groupadd -g 1000 ast_grp && \
    useradd -m -u 1000 -g ast_grp ast_usr

# Change active user
USER ast_usr

# Establecer directorio de trabajo
WORKDIR /app

# Comando por defecto: compilar todo al entrar
CMD ["make", "all"]
