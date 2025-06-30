# Сборка
FROM ubuntu:22.04 AS builder

# Установка базовых зависимостей
RUN apt-get update && \
    apt-get install -y \
    git \
    curl \
    build-essential \
    cmake \
    pkg-config \
    tar \
    zip \
    unzip

# Установка vcpkg (отдельный слой для кэширования)
RUN git clone https://github.com/Microsoft/vcpkg.git
WORKDIR /vcpkg
RUN ./bootstrap-vcpkg.sh

# Установка Drogon через vcpkg (отдельный слой для кэширования)
RUN ./vcpkg install drogon

# Копирование проекта
WORKDIR /app
COPY . .

# Сборка проекта с использованием vcpkg toolchain
RUN mkdir -p build && \
    cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release \
          -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake .. && \
    make -j$(nproc)

# Запуск
FROM ubuntu:22.04
WORKDIR /app

# Установка runtime-зависимостей
RUN apt-get update && \
    apt-get install -y \
    libjsoncpp25 \
    libuuid1 \
    libssl3 \
    zlib1g \
    libc-ares2 \
    libbrotli1 \
    libzstd1 && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/build/cpp-simple-api .
CMD ["./cpp-simple-api"]