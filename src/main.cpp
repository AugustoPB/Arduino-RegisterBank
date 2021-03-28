#include <Arduino.h>
#include <register.h>


Register<uint32_t,"teste1"_hash> my_register;

Register<uint16_t,"teste2"_hash> my_register2;

void setup() {
  Serial.begin(115200);
  RegisterBank::Get<"teste1"_hash>()->Set<uint32_t>(32);
}

void loop() {
  RegisterInterface *reg = RegisterBank::Get<"teste1"_hash>();
  if (reg)
    Serial.println(reg->Get<uint32_t>());
  delay(1000);
}