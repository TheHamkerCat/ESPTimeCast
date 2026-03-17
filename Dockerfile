FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    curl \
    git \
    python3 \
    python3-serial \
    && rm -rf /var/lib/apt/lists/*

# Install arduino-cli (pinned)
ARG ARDUINO_CLI_VERSION=1.4.1
RUN curl -fsSL "https://downloads.arduino.cc/arduino-cli/arduino-cli_${ARDUINO_CLI_VERSION}_Linux_64bit.tar.gz" -o /tmp/arduino-cli.tar.gz && \
    tar -xzf /tmp/arduino-cli.tar.gz -C /usr/local/bin arduino-cli && \
    rm /tmp/arduino-cli.tar.gz

# Configure ESP32 board support
RUN arduino-cli config init && \
    arduino-cli config add board_manager.additional_urls \
      https://espressif.github.io/arduino-esp32/package_esp32_index.json && \
    arduino-cli config set library.enable_unsafe_install true && \
    arduino-cli core update-index && \
    arduino-cli core install esp32:esp32

# Install required libraries
RUN arduino-cli lib install "ArduinoJson" "MD_Parola" "MD_MAX72xx" && \
    arduino-cli lib install --git-url https://github.com/mathieucarbou/ESPAsyncWebServer.git && \
    arduino-cli lib install --git-url https://github.com/mathieucarbou/AsyncTCP.git

WORKDIR /workspace
