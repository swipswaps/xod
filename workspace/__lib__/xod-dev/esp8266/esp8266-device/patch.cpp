{{#global}}
#include <ESP8266UART.h>
{{/global}}

struct State {
    uint8_t mem[sizeof(ESP8266)];
    ESP8266* wifi;
};
struct Type {
    Uart* uart;
    ESP8266* wifi;
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    if (!isInputDirty<input_INIT>(ctx))
        return;

    auto state = getState(ctx);
    auto uart = getValue<input_UART>(ctx);

    state->wifi = new (state->mem) ESP8266(*uart);
    Type obj = { uart, state->wifi };
    state->wifi->begin();

    emitValue<output_DEV>(ctx, obj);
    emitValue<output_DONE>(ctx, 1);
}
