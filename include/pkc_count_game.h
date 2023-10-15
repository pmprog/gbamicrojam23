#ifndef TMG_TEST_GAME_H
#define TMG_TEST_GAME_H

#include "bn_regular_bg_ptr.h"

#include "mj/mj_game.h"

namespace pkc
{

class pumpkincount : public mj::game
{

public:
    pumpkincount(int completed_games, const mj::game_data& data);

    [[nodiscard]] bn::string<16> title() const final
    {
        return "Count Pumpkins!";
    }

    [[nodiscard]] int total_frames() const final
    {
        return _total_frames;
    }

    void fade_in(const mj::game_data& data) final;

    [[nodiscard]] mj::game_result play(const mj::game_data& data) final;

    [[nodiscard]] bool victory() const final
    {
        return _victory;
    }

    void fade_out(const mj::game_data& data) final;

private:
    bn::regular_bg_ptr _bg;
    bn::regular_bg_ptr _bgov;
    int _total_frames;
    int _show_result_frames = 60;
    bool _victory = false;
    bool _defeat = false;
};

}

#endif
