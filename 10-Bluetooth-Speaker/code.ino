#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  // Pin configurations for MAX98357A I2S DAC Module
  i2s_pin_config_t my_pin_config = {
    .bck_io_num = 26,   // BCLK (Bit Clock)
    .ws_io_num = 25,    // LRC (Left/Right Clock / WS)
    .data_out_num = 22, // DIN (Data In)
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.start("ESP32-Audio-Speaker");
}

void loop() {
  // Audio streaming is handled asynchronously by the A2DP Sink library tasks
}
