#include "pkc_count_game.h"

#include "bn_keypad.h"

#include "mj/mj_game_list.h"

#include "bn_regular_bg_items_pkc_patch.h"
#include "bn_regular_bg_items_pkc_overlay.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "pmprog" };
    constexpr bn::string_view graphics_credits[] = { "pmprog" };
}

MJ_GAME_LIST_ADD(pkc::pumpkincount)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
// MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
// MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace pkc
{

pumpkincount::pumpkincount(int completed_games, const mj::game_data& data) :
    _bg(bn::regular_bg_items::pkc_patch.create_bg((256 - 240) / 2, (256 - 160) / 2)),
    _bgov(bn::regular_bg_items::pkc_overlay.create_bg((256 - 240) / 2, (256 - 160) / 2)),
    _total_frames(play_jingle(mj::game_jingle_type::METRONOME_16BEAT, completed_games, data))
{
}

void pumpkincount::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

mj::game_result pumpkincount::play(const mj::game_data& data)
{
    mj::game_result result;
    result.exit = data.pending_frames == 0;

    if(! _victory && ! _defeat)
    {
    }
    else
    {
        if(_show_result_frames)
        {
            --_show_result_frames;
        }
        else
        {
            result.exit = true;
        }
    }

    return result;
}

void pumpkincount::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

}
