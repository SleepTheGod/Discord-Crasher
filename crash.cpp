#include <dpp/dpp.h>

int main() {
    dpp::cluster bot("your_token_here");

    bot.on_log(dpp::utility::cout_logger());

    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        if (event.msg.content == "!send") {
            std::string channel_id = "channel_id_here"; // Replace with your channel ID
            std::string message = "http://./\\<#0>:  ://./<#0>"; // The message to send

            bot.message_create(dpp::message(channel_id, message), [](const dpp::confirmation_callback_t& confirmation) {
                if (!confirmation.is_error()) {
                    std::cout << "Message sent successfully!" << std::endl;
                } else {
                    std::cerr << "Failed to send message!" << std::endl;
                }
            });
        }
    });

    bot.start(dpp::st_wait);
}
