#include "draw_a_Whale.h"

void Draw_a_Whale::draw(){

    //Dark Color Pick
    SDL_Color const dark_black = {0, 0, 0, 255};
    SDL_Color const middle_black = {33, 33, 33, 255};
    SDL_Color const light_black = {66, 67, 67, 255};

    //Grey Color Pick
    SDL_Color const dark_grey = {142, 142, 142, 245};
    SDL_Color const middle_grey = {174, 172, 172, 240};
    SDL_Color const light_grey = {219, 219, 219, 227};

    //White Color Pick
    //SDL_Color const pure_white = {255, 255, 255, 255};
    SDL_Color const middle_white = {234, 234, 234, 255};
    SDL_Color const dark_white = {214, 214, 214, 234};

    //Blue
    SDL_Color const blue = {54, 225, 251, 255};

    //Whale's Head upper half(black area)
    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_1_1(63, 202);
    Vector2f head_triangle_1_2(39, 218);
    Vector2f head_triangle_1_3(49, 193);
    Draw_filled_Triangle head_triangle_1(renderer, head_triangle_1_1, head_triangle_1_2, head_triangle_1_3);
    head_triangle_1.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f head_triangle_2_1(63, 202);
    Vector2f head_triangle_2_2(69, 181);
    Vector2f head_triangle_2_3(49, 193);
    Draw_filled_Triangle head_triangle_2(renderer, head_triangle_2_1, head_triangle_2_2, head_triangle_2_3);
    head_triangle_2.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f head_triangle_3_1(80, 148);
    Vector2f head_triangle_3_2(69, 181);
    Vector2f head_triangle_3_3(49, 193);
    Draw_filled_Triangle head_triangle_3(renderer, head_triangle_3_1, head_triangle_3_2, head_triangle_3_3);
    head_triangle_3.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_4_1(63, 202);
    Vector2f head_triangle_4_2(69, 181);
    Vector2f head_triangle_4_3(97, 194);
    Draw_filled_Triangle head_triangle_4(renderer, head_triangle_4_1, head_triangle_4_2, head_triangle_4_3);
    head_triangle_4.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f head_triangle_5_1(110, 157);
    Vector2f head_triangle_5_2(69, 181);
    Vector2f head_triangle_5_3(97, 194);
    Draw_filled_Triangle head_triangle_5(renderer, head_triangle_5_1, head_triangle_5_2, head_triangle_5_3);
    head_triangle_5.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_6_1(69, 181);
    Vector2f head_triangle_6_2(80, 148);
    Vector2f head_triangle_6_3(108, 160);
    Draw_filled_Triangle head_triangle_6(renderer, head_triangle_6_1, head_triangle_6_2, head_triangle_6_3);
    head_triangle_6.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_7_1(108, 160);
    Vector2f head_triangle_7_2(97, 194);
    Vector2f head_triangle_7_3(135, 192);
    Draw_filled_Triangle head_triangle_7(renderer, head_triangle_7_1, head_triangle_7_2, head_triangle_7_3);
    head_triangle_7.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_8_1(108, 160);
    Vector2f head_triangle_8_2(80, 148);
    Vector2f head_triangle_8_3(125, 124);
    Draw_filled_Triangle head_triangle_8(renderer, head_triangle_8_1, head_triangle_8_2, head_triangle_8_3);
    head_triangle_8.draw_trianle();

    Vector2f head_triangle_9_1(125, 124);
    Vector2f head_triangle_9_2(108, 160);
    Vector2f head_triangle_9_3(150, 152);
    Draw_filled_Triangle head_triangle_9(renderer, head_triangle_9_1, head_triangle_9_2, head_triangle_9_3);
    head_triangle_9.draw_trianle();

    Vector2f head_triangle_10_1(125, 124);
    Vector2f head_triangle_10_2(150, 152);
    Vector2f head_triangle_10_3(168, 142);
    Draw_filled_Triangle head_triangle_10(renderer, head_triangle_10_1, head_triangle_10_2, head_triangle_10_3);
    head_triangle_10.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_11_1(108, 160);
    Vector2f head_triangle_11_2(150, 152);
    Vector2f head_triangle_11_3(158, 168);
    Draw_filled_Triangle head_triangle_11(renderer, head_triangle_11_1, head_triangle_11_2, head_triangle_11_3);
    head_triangle_11.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_12_1(108, 160);
    Vector2f head_triangle_12_2(135, 192);
    Vector2f head_triangle_12_3(158, 168);
    Draw_filled_Triangle head_triangle_12(renderer, head_triangle_12_1, head_triangle_12_2, head_triangle_12_3);
    head_triangle_12.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_13_1(158, 168);
    Vector2f head_triangle_13_2(135, 192);
    Vector2f head_triangle_13_3(176, 195);
    Draw_filled_Triangle head_triangle_13(renderer, head_triangle_13_1, head_triangle_13_2, head_triangle_13_3);
    head_triangle_13.draw_trianle();

    Vector2f head_triangle_14_1(158, 168);
    Vector2f head_triangle_14_2(176, 195);
    Vector2f head_triangle_14_3(188, 168);
    Draw_filled_Triangle head_triangle_14(renderer, head_triangle_14_1, head_triangle_14_2, head_triangle_14_3);
    head_triangle_14.draw_trianle();

    Vector2f head_triangle_15_1(125, 124);
    Vector2f head_triangle_15_2(168, 142);
    Vector2f head_triangle_15_3(225, 120);
    Draw_filled_Triangle head_triangle_15(renderer, head_triangle_15_1, head_triangle_15_2, head_triangle_15_3);
    head_triangle_15.draw_trianle();

    Vector2f head_triangle_16_1(225, 120);
    Vector2f head_triangle_16_2(280, 120);
    Vector2f head_triangle_16_3(266, 146);
    Draw_filled_Triangle head_triangle_16(renderer, head_triangle_16_1, head_triangle_16_2, head_triangle_16_3);
    head_triangle_16.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f head_triangle_17_1(188, 168);
    Vector2f head_triangle_17_2(176, 195);
    Vector2f head_triangle_17_3(204, 184);
    Draw_filled_Triangle head_triangle_17(renderer, head_triangle_17_1, head_triangle_17_2, head_triangle_17_3);
    head_triangle_17.draw_trianle();

    Vector2f head_triangle_18_1(188, 168);
    Vector2f head_triangle_18_2(204, 184);
    Vector2f head_triangle_18_3(223, 177);
    Draw_filled_Triangle head_triangle_18(renderer, head_triangle_18_1, head_triangle_18_2, head_triangle_18_3);
    head_triangle_18.draw_trianle();

    Vector2f head_triangle_19_1(215, 165);
    Vector2f head_triangle_19_2(242, 207);
    Vector2f head_triangle_19_3(240, 177);
    Draw_filled_Triangle head_triangle_19(renderer, head_triangle_19_1, head_triangle_19_2, head_triangle_19_3);
    head_triangle_19.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_20_1(215, 165);
    Vector2f head_triangle_20_2(188, 168);
    Vector2f head_triangle_20_3(223, 177);
    Draw_filled_Triangle head_triangle_20(renderer, head_triangle_20_1, head_triangle_20_2, head_triangle_20_3);
    head_triangle_20.draw_trianle();

    Vector2f head_triangle_21_1(240, 177);
    Vector2f head_triangle_21_2(250, 173);
    Vector2f head_triangle_21_3(242, 207);
    Draw_filled_Triangle head_triangle_21(renderer, head_triangle_21_1, head_triangle_21_2, head_triangle_21_3);
    head_triangle_21.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_22_1(168, 142);
    Vector2f head_triangle_22_2(225, 120);
    Vector2f head_triangle_22_3(214, 141);
    Draw_filled_Triangle head_triangle_22(renderer, head_triangle_22_1, head_triangle_22_2, head_triangle_22_3);
    head_triangle_22.draw_trianle();

    Vector2f head_triangle_23_1(225, 120);
    Vector2f head_triangle_23_2(214, 141);
    Vector2f head_triangle_23_3(264, 145);
    Draw_filled_Triangle head_triangle_23(renderer, head_triangle_23_1, head_triangle_23_2, head_triangle_23_3);
    head_triangle_23.draw_trianle();

    Vector2f head_triangle_24_1(214, 141);
    Vector2f head_triangle_24_2(266, 146);
    Vector2f head_triangle_24_3(244, 159);
    Draw_filled_Triangle head_triangle_24(renderer, head_triangle_24_1, head_triangle_24_2, head_triangle_24_3);
    head_triangle_24.draw_trianle();

    Vector2f head_triangle_25_1(250, 173);
    Vector2f head_triangle_25_2(266, 146);
    Vector2f head_triangle_25_3(244, 159);
    Draw_filled_Triangle head_triangle_25(renderer, head_triangle_25_1, head_triangle_25_2, head_triangle_25_3);
    head_triangle_25.draw_trianle();

    //Whale's Head eyes half(white area) 11 14 15
    SDL_SetRenderDrawColor(renderer, middle_white.r, middle_white.g, middle_white.b, middle_white.a);
    Vector2f head_triangle_26_1(150, 152);
    Vector2f head_triangle_26_2(168, 142);
    Vector2f head_triangle_26_3(158, 168);
    Draw_filled_Triangle head_triangle_26(renderer, head_triangle_26_1, head_triangle_26_2, head_triangle_26_3);
    head_triangle_26.draw_trianle();

    Vector2f head_triangle_27_1(168, 142);
    Vector2f head_triangle_27_2(186, 140);
    Vector2f head_triangle_27_3(188, 168);
    Draw_filled_Triangle head_triangle_27(renderer, head_triangle_27_1, head_triangle_27_2, head_triangle_27_3);
    head_triangle_27.draw_trianle();

    Vector2f head_triangle_28_1(188, 168);
    Vector2f head_triangle_28_2(214, 141);
    Vector2f head_triangle_28_3(215, 165);
    Draw_filled_Triangle head_triangle_28(renderer, head_triangle_28_1, head_triangle_28_2, head_triangle_28_3);
    head_triangle_28.draw_trianle();

    Vector2f head_triangle_29_1(215, 165);
    Vector2f head_triangle_29_2(244, 159);
    Vector2f head_triangle_29_3(240, 177);
    Draw_filled_Triangle head_triangle_29(renderer, head_triangle_29_1, head_triangle_29_2, head_triangle_29_3);
    head_triangle_29.draw_trianle();

    //Whale's Head lower half(white area)
    SDL_SetRenderDrawColor(renderer, dark_white.r, dark_white.g, dark_white.b, dark_white.a);
    Vector2f head_triangle_30_1(39, 218);
    Vector2f head_triangle_30_2(61, 237);
    Vector2f head_triangle_30_3(63, 202);
    Draw_filled_Triangle head_triangle_30(renderer, head_triangle_30_1, head_triangle_30_2, head_triangle_30_3);
    head_triangle_30.draw_trianle();

    Vector2f head_triangle_31_1(61, 237);
    Vector2f head_triangle_31_2(63, 202);
    Vector2f head_triangle_31_3(93, 229);
    Draw_filled_Triangle head_triangle_31(renderer, head_triangle_31_1, head_triangle_31_2, head_triangle_31_3);
    head_triangle_31.draw_trianle();

    Vector2f head_triangle_32_1(93, 229);
    Vector2f head_triangle_32_2(161, 238);
    Vector2f head_triangle_32_3(114, 258);
    Draw_filled_Triangle head_triangle_32(renderer, head_triangle_32_1, head_triangle_32_2, head_triangle_32_3);
    head_triangle_32.draw_trianle();

    Vector2f head_triangle_33_1(161, 238);
    Vector2f head_triangle_33_2(166, 261);
    Vector2f head_triangle_33_3(205, 222);
    Draw_filled_Triangle head_triangle_33(renderer, head_triangle_33_1, head_triangle_33_2, head_triangle_33_3);
    head_triangle_33.draw_trianle();

    Vector2f head_triangle_34_1(166, 261);
    //Fin Joint
    Vector2f head_triangle_34_2(215, 276);
    Vector2f head_triangle_34_3(218, 256);
    Draw_filled_Triangle head_triangle_34(renderer, head_triangle_34_1, head_triangle_34_2, head_triangle_34_3);
    head_triangle_34.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_grey.r, light_grey.g, light_grey.b, light_grey.a);
    Vector2f head_triangle_35_1(61, 237);
    Vector2f head_triangle_35_2(93, 229);
    Vector2f head_triangle_35_3(114, 258);
    Draw_filled_Triangle head_triangle_35(renderer, head_triangle_35_1, head_triangle_35_2, head_triangle_35_3);
    head_triangle_35.draw_trianle();

    Vector2f head_triangle_36_3(114, 258);
    Vector2f head_triangle_36_2(166, 261);
    Vector2f head_triangle_36_1(161, 238);
    Draw_filled_Triangle head_triangle_36(renderer, head_triangle_36_1, head_triangle_36_2, head_triangle_36_3);
    head_triangle_36.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_grey.r, middle_grey.g, middle_grey.b, middle_grey.a);
    Vector2f head_triangle_37_1(166, 261);
    Vector2f head_triangle_37_2(204, 223);
    Vector2f head_triangle_37_3(218, 256);
    Draw_filled_Triangle head_triangle_37(renderer, head_triangle_37_1, head_triangle_37_2, head_triangle_37_3);
    head_triangle_37.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_grey.r, dark_grey.g, dark_grey.b, dark_grey.a);
    Vector2f head_triangle_38_1(204, 223);
    Vector2f head_triangle_38_2(218, 256);
    Vector2f head_triangle_38_3(241, 209);
    Draw_filled_Triangle head_triangle_38(renderer, head_triangle_38_1, head_triangle_38_2, head_triangle_38_3);
    head_triangle_38.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_white.r, middle_white.g, middle_white.b, middle_white.a);
    Vector2f head_triangle_39_1(93, 229);
    Vector2f head_triangle_39_2(161, 238);
    Vector2f head_triangle_39_3(135, 192);
    Draw_filled_Triangle head_triangle_39(renderer, head_triangle_39_1, head_triangle_39_2, head_triangle_39_3);
    head_triangle_39.draw_trianle();

    Vector2f head_triangle_40_1(63, 202);
    Vector2f head_triangle_40_2(93, 229);
    Vector2f head_triangle_40_3(97, 194);
    Draw_filled_Triangle head_triangle_40(renderer, head_triangle_40_1, head_triangle_40_2, head_triangle_40_3);
    head_triangle_40.draw_trianle();

    Vector2f head_triangle_41_1(176, 195);
    Vector2f head_triangle_41_2(161, 238);
    Vector2f head_triangle_41_3(204, 223);
    Draw_filled_Triangle head_triangle_41(renderer, head_triangle_41_1, head_triangle_41_2, head_triangle_41_3);
    head_triangle_41.draw_trianle();

    //Whale's Fin
    //body part(black)
    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_42_1(280, 120);
    Vector2f head_triangle_42_2(266, 146);
    Vector2f head_triangle_42_3(323, 130);
    Draw_filled_Triangle head_triangle_42(renderer, head_triangle_42_1, head_triangle_42_2, head_triangle_42_3);
    head_triangle_42.draw_trianle();

    Vector2f head_triangle_43_1(330, 180);
    Vector2f head_triangle_43_2(266, 146);
    Vector2f head_triangle_43_3(279, 196);
    Draw_filled_Triangle head_triangle_43(renderer, head_triangle_43_1, head_triangle_43_2, head_triangle_43_3);
    head_triangle_43.draw_trianle();

    Vector2f head_triangle_44_1(323, 130);
    Vector2f head_triangle_44_2(330, 180);
    Vector2f head_triangle_44_3(357, 151);
    Draw_filled_Triangle head_triangle_44(renderer, head_triangle_44_1, head_triangle_44_2, head_triangle_44_3);
    head_triangle_44.draw_trianle();

    Vector2f head_triangle_45_1(250, 173);
    Vector2f head_triangle_45_2(241, 209);
    Vector2f head_triangle_45_3(279, 196);
    Draw_filled_Triangle head_triangle_45(renderer, head_triangle_45_1, head_triangle_45_2, head_triangle_45_3);
    head_triangle_45.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_46_1(266, 146);
    Vector2f head_triangle_46_2(330, 180);
    Vector2f head_triangle_46_3(323, 130);
    Draw_filled_Triangle head_triangle_46(renderer, head_triangle_46_1, head_triangle_46_2, head_triangle_46_3);
    head_triangle_46.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f head_triangle_47_1(266, 146);
    Vector2f head_triangle_47_2(250, 173);
    Vector2f head_triangle_47_3(279, 196);
    Draw_filled_Triangle head_triangle_47(renderer, head_triangle_47_1, head_triangle_47_2, head_triangle_47_3);
    head_triangle_47.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_grey.r, dark_grey.g, dark_grey.b, dark_grey.a);
    //body connect point
    Vector2f head_triangle_48_1(279, 196);
    Vector2f head_triangle_48_2(330, 180);
    Vector2f head_triangle_48_3(308, 225);
    Draw_filled_Triangle head_triangle_48(renderer, head_triangle_48_1, head_triangle_48_2, head_triangle_48_3);
    head_triangle_48.draw_trianle();

    //body part(white)
    Vector2f head_triangle_49_1(241, 209);
    Vector2f head_triangle_49_2(218, 256);
    Vector2f head_triangle_49_3(283, 268);
    Draw_filled_Triangle head_triangle_49(renderer, head_triangle_49_1, head_triangle_49_2, head_triangle_49_3);
    head_triangle_49.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_grey.r, light_grey.g, light_grey.b, light_grey.a);
    Vector2f head_triangle_50_1(241, 209);
    Vector2f head_triangle_50_2(218, 256);
    Vector2f head_triangle_50_3(204, 223);
    Draw_filled_Triangle head_triangle_50(renderer, head_triangle_50_1, head_triangle_50_2, head_triangle_50_3);
    head_triangle_50.draw_trianle();

    Vector2f head_triangle_51_1(218, 256);
    Vector2f head_triangle_51_2(215, 276);
    Vector2f head_triangle_51_3(283, 268);
    Draw_filled_Triangle head_triangle_51(renderer, head_triangle_51_1, head_triangle_51_2, head_triangle_51_3);
    head_triangle_51.draw_trianle();

    Vector2f head_triangle_52_1(283, 268);
    Vector2f head_triangle_52_2(275, 295);
    Vector2f head_triangle_52_3(323, 301);
    Draw_filled_Triangle head_triangle_52(renderer, head_triangle_52_1, head_triangle_52_2, head_triangle_52_3);
    head_triangle_52.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_white.r, dark_white.g, dark_white.b, dark_white.a);
    Vector2f head_triangle_53_1(215, 276);
    Vector2f head_triangle_53_2(275, 295);
    Vector2f head_triangle_53_3(283, 268);
    Draw_filled_Triangle head_triangle_53(renderer, head_triangle_53_1, head_triangle_53_2, head_triangle_53_3);
    head_triangle_53.draw_trianle();

    //Right Fin
    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_54_1(241, 209);
    Vector2f head_triangle_54_2(279, 196);
    Vector2f head_triangle_54_3(283, 268);
    Draw_filled_Triangle head_triangle_54(renderer, head_triangle_54_1, head_triangle_54_2, head_triangle_54_3);
    head_triangle_54.draw_trianle();

    Vector2f head_triangle_55_1(323, 301);
    Vector2f head_triangle_55_2(283, 268);
    Vector2f head_triangle_55_3(304, 263);
    Draw_filled_Triangle head_triangle_55(renderer, head_triangle_55_1, head_triangle_55_2, head_triangle_55_3);
    head_triangle_55.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_56_1(279, 196);
    Vector2f head_triangle_56_2(308, 225);
    Vector2f head_triangle_56_3(283, 268);
    Draw_filled_Triangle head_triangle_56(renderer, head_triangle_56_1, head_triangle_56_2, head_triangle_56_3);
    head_triangle_56.draw_trianle();

    Vector2f head_triangle_57_1(308, 225);
    Vector2f head_triangle_57_2(283, 268);
    Vector2f head_triangle_57_3(326, 262);
    Draw_filled_Triangle head_triangle_57(renderer, head_triangle_57_1, head_triangle_57_2, head_triangle_57_3);
    head_triangle_57.draw_trianle();

    Vector2f head_triangle_58_1(304, 263);
    Vector2f head_triangle_58_2(323, 301);
    Vector2f head_triangle_58_3(326, 262);
    Draw_filled_Triangle head_triangle_58(renderer, head_triangle_58_1, head_triangle_58_2, head_triangle_58_3);
    head_triangle_58.draw_trianle();

    //Left Fin
    Vector2f head_triangle_59_1(166, 261);
    Vector2f head_triangle_59_2(161, 307);
    Vector2f head_triangle_59_3(182, 287);
    Draw_filled_Triangle head_triangle_59(renderer, head_triangle_59_1, head_triangle_59_2, head_triangle_59_3);
    head_triangle_59.draw_trianle();

    Vector2f head_triangle_60_2(161, 307);
    Vector2f head_triangle_60_3(182, 287);
    Vector2f head_triangle_60_1(182, 314);
    Draw_filled_Triangle head_triangle_60(renderer, head_triangle_60_1, head_triangle_60_2, head_triangle_60_3);
    head_triangle_60.draw_trianle();

    Vector2f head_triangle_61_1(215, 276);
    Vector2f head_triangle_61_2(182, 314);
    Vector2f head_triangle_61_3(190, 377);
    Draw_filled_Triangle head_triangle_61(renderer, head_triangle_61_1, head_triangle_61_2, head_triangle_61_3);
    head_triangle_61.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_62_1(166, 261);
    Vector2f head_triangle_62_2(215, 276);
    Vector2f head_triangle_62_3(182, 287);
    Draw_filled_Triangle head_triangle_62(renderer, head_triangle_62_1, head_triangle_62_2, head_triangle_62_3);
    head_triangle_62.draw_trianle();

    Vector2f head_triangle_63_1(215, 276);
    Vector2f head_triangle_63_2(182, 287);
    Vector2f head_triangle_63_3(182, 314);
    Draw_filled_Triangle head_triangle_63(renderer, head_triangle_63_1, head_triangle_63_2, head_triangle_63_3);
    head_triangle_63.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f head_triangle_64_1(182, 314);
    Vector2f head_triangle_64_2(170, 351);
    Vector2f head_triangle_64_3(161, 307);
    Draw_filled_Triangle head_triangle_64(renderer, head_triangle_64_1, head_triangle_64_2, head_triangle_64_3);
    head_triangle_64.draw_trianle();

    Vector2f head_triangle_65_1(182, 314);
    Vector2f head_triangle_65_2(170, 351);
    Vector2f head_triangle_65_3(190, 377);
    Draw_filled_Triangle head_triangle_65(renderer, head_triangle_65_1, head_triangle_65_2, head_triangle_65_3);
    head_triangle_65.draw_trianle();

    // Upper Fin
    Vector2f head_triangle_66_1(323, 130);
    Vector2f head_triangle_66_2(362, 100);
    Vector2f head_triangle_66_3(344, 83);
    Draw_filled_Triangle head_triangle_66(renderer, head_triangle_66_1, head_triangle_66_2, head_triangle_66_3);
    head_triangle_66.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_67_1(323, 130);
    Vector2f head_triangle_67_2(344, 83);
    Vector2f head_triangle_67_3(310, 75);
    Draw_filled_Triangle head_triangle_67(renderer, head_triangle_67_1, head_triangle_67_2, head_triangle_67_3);
    head_triangle_67.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f head_triangle_68_1(310, 75);
    Vector2f head_triangle_68_2(280, 120);
    Vector2f head_triangle_68_3(323, 130);
    Draw_filled_Triangle head_triangle_68(renderer, head_triangle_68_1, head_triangle_68_2, head_triangle_68_3);
    head_triangle_68.draw_trianle();

    Vector2f head_triangle_69_1(310, 75);
    Vector2f head_triangle_69_2(351, 59);
    Vector2f head_triangle_69_3(344, 83);
    Draw_filled_Triangle head_triangle_69(renderer, head_triangle_69_1, head_triangle_69_2, head_triangle_69_3);
    head_triangle_69.draw_trianle();

    Vector2f head_triangle_70_1(344, 83);
    Vector2f head_triangle_70_2(362, 100);
    Vector2f head_triangle_70_3(372, 62);
    Draw_filled_Triangle head_triangle_70(renderer, head_triangle_70_1, head_triangle_70_2, head_triangle_70_3);
    head_triangle_70.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f head_triangle_71_1(351, 59);
    Vector2f head_triangle_71_2(372, 62);
    Vector2f head_triangle_71_3(344, 83);
    Draw_filled_Triangle head_triangle_71(renderer, head_triangle_71_1, head_triangle_71_2, head_triangle_71_3);
    head_triangle_71.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_grey.r, dark_grey.g, dark_grey.b, dark_grey.a);
    Vector2f head_triangle_72_1(362, 100);
    Vector2f head_triangle_72_2(323, 130);
    Vector2f head_triangle_72_3(356, 127);
    Draw_filled_Triangle head_triangle_72(renderer, head_triangle_72_1, head_triangle_72_2, head_triangle_72_3);
    head_triangle_72.draw_trianle();

    Vector2f head_triangle_73_1(356, 127);
    Vector2f head_triangle_73_2(323, 130);
    Vector2f head_triangle_73_3(357, 151);
    Draw_filled_Triangle head_triangle_73(renderer, head_triangle_73_1, head_triangle_73_2, head_triangle_73_3);
    head_triangle_73.draw_trianle();

    /**
     * Head Finished! 
    **/ 

    //Body(black & grey)
    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f body_triangle_1_1(330, 180);
    Vector2f body_triangle_1_2(357, 151);
    Vector2f body_triangle_1_3(373, 218);
    Draw_filled_Triangle body_triangle_1(renderer, body_triangle_1_1, body_triangle_1_2, body_triangle_1_3);
    body_triangle_1.draw_trianle();

    Vector2f body_triangle_2_1(357, 151);
    Vector2f body_triangle_2_2(373, 218);
    Vector2f body_triangle_2_3(399, 200);
    Draw_filled_Triangle body_triangle_2(renderer, body_triangle_2_1, body_triangle_2_2, body_triangle_2_3);
    body_triangle_2.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f body_triangle_3_1(330, 180);
    Vector2f body_triangle_3_2(308, 225);
    Vector2f body_triangle_3_3(340, 210);
    Draw_filled_Triangle body_triangle_3(renderer, body_triangle_3_1, body_triangle_3_2, body_triangle_3_3);
    body_triangle_3.draw_trianle();

    Vector2f body_triangle_4_1(330, 180);
    Vector2f body_triangle_4_2(340, 210);
    Vector2f body_triangle_4_3(370, 218);
    Draw_filled_Triangle body_triangle_4(renderer, body_triangle_4_1, body_triangle_4_2, body_triangle_4_3);
    body_triangle_4.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f body_triangle_5_1(413, 184);
    Vector2f body_triangle_5_2(399, 200);
    Vector2f body_triangle_5_3(450, 235);
    Draw_filled_Triangle body_triangle_5(renderer, body_triangle_5_1, body_triangle_5_2, body_triangle_5_3);
    body_triangle_5.draw_trianle();

    Vector2f body_triangle_6_1(450, 235);
    Vector2f body_triangle_6_2(469, 269);
    Vector2f body_triangle_6_3(475, 227);
    Draw_filled_Triangle body_triangle_6(renderer, body_triangle_6_1, body_triangle_6_2, body_triangle_6_3);
    body_triangle_6.draw_trianle();

    Vector2f body_triangle_7_1(535, 291);
    Vector2f body_triangle_7_2(502, 288);
    Vector2f body_triangle_7_3(513, 321);
    Draw_filled_Triangle body_triangle_7(renderer, body_triangle_7_1, body_triangle_7_2, body_triangle_7_3);
    body_triangle_7.draw_trianle();

    Vector2f body_triangle_8_1(513, 321);
    Vector2f body_triangle_8_2(563, 337);
    Vector2f body_triangle_8_3(554, 386);
    Draw_filled_Triangle body_triangle_8(renderer, body_triangle_8_1, body_triangle_8_2, body_triangle_8_3);
    body_triangle_8.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f body_triangle_9_1(370, 218);
    Vector2f body_triangle_9_2(399, 200);
    Vector2f body_triangle_9_3(425, 264);
    Draw_filled_Triangle body_triangle_9(renderer, body_triangle_9_1, body_triangle_9_2, body_triangle_9_3);
    body_triangle_9.draw_trianle();

    Vector2f body_triangle_10_2(399, 200);
    Vector2f body_triangle_10_3(425, 264);
    Vector2f body_triangle_10_1(450, 235);
    Draw_filled_Triangle body_triangle_10(renderer, body_triangle_10_1, body_triangle_10_2, body_triangle_10_3);
    body_triangle_10.draw_trianle();

    Vector2f body_triangle_11_1(425, 264);
    Vector2f body_triangle_11_2(450, 235);
    Vector2f body_triangle_11_3(469, 269);
    Draw_filled_Triangle body_triangle_11(renderer, body_triangle_11_1, body_triangle_11_2, body_triangle_11_3);
    body_triangle_11.draw_trianle();

    Vector2f body_triangle_12_1(513, 321);
    Vector2f body_triangle_12_2(535, 291);
    Vector2f body_triangle_12_3(563, 337);
    Draw_filled_Triangle body_triangle_12(renderer, body_triangle_12_1, body_triangle_12_2, body_triangle_12_3);
    body_triangle_12.draw_trianle();

    Vector2f body_triangle_13_1(563, 337);
    Vector2f body_triangle_13_2(554, 386);
    Vector2f body_triangle_13_3(593, 382);
    Draw_filled_Triangle body_triangle_13(renderer, body_triangle_13_1, body_triangle_13_2, body_triangle_13_3);
    body_triangle_13.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f body_triangle_14_1(357, 151);
    Vector2f body_triangle_14_2(399, 200);
    Vector2f body_triangle_14_3(413, 184);
    Draw_filled_Triangle body_triangle_14(renderer, body_triangle_14_1, body_triangle_14_2, body_triangle_14_3);
    body_triangle_14.draw_trianle();

    Vector2f body_triangle_15_2(413, 184);
    Vector2f body_triangle_15_1(450, 235);
    Vector2f body_triangle_15_3(475, 227);
    Draw_filled_Triangle body_triangle_15(renderer, body_triangle_15_1, body_triangle_15_2, body_triangle_15_3);
    body_triangle_15.draw_trianle();

    Vector2f body_triangle_16_1(475, 227);
    Vector2f body_triangle_16_2(469, 269);
    Vector2f body_triangle_16_3(535, 291);
    Draw_filled_Triangle body_triangle_16(renderer, body_triangle_16_1, body_triangle_16_2, body_triangle_16_3);
    body_triangle_16.draw_trianle();

    Vector2f body_triangle_17_1(469, 269);
    Vector2f body_triangle_17_2(502, 288);
    Vector2f body_triangle_17_3(535, 291);
    Draw_filled_Triangle body_triangle_17(renderer, body_triangle_17_1, body_triangle_17_2, body_triangle_17_3);
    body_triangle_17.draw_trianle();

    Vector2f body_triangle_18_1(513, 321);
    Vector2f body_triangle_18_2(554, 386);
    Vector2f body_triangle_18_3(534, 386);
    Draw_filled_Triangle body_triangle_18(renderer, body_triangle_18_1, body_triangle_18_2, body_triangle_18_3);
    body_triangle_18.draw_trianle();

    Vector2f body_triangle_19_1(513, 321);
    Vector2f body_triangle_19_2(488, 355);
    Vector2f body_triangle_19_3(534, 386);
    Draw_filled_Triangle body_triangle_19(renderer, body_triangle_19_1, body_triangle_19_2, body_triangle_19_3);
    body_triangle_19.draw_trianle();

    Vector2f body_triangle_20_1(488, 355);
    Vector2f body_triangle_20_2(513, 321);
    Vector2f body_triangle_20_3(479, 326);
    Draw_filled_Triangle body_triangle_20(renderer, body_triangle_20_1, body_triangle_20_2, body_triangle_20_3);
    body_triangle_20.draw_trianle();

    Vector2f body_triangle_21_1(479, 326);
    Vector2f body_triangle_21_2(488, 355);
    Vector2f body_triangle_21_3(392, 323);
    Draw_filled_Triangle body_triangle_21(renderer, body_triangle_21_1, body_triangle_21_2, body_triangle_21_3);
    body_triangle_21.draw_trianle();

    Vector2f body_triangle_22_1(479, 326);
    Vector2f body_triangle_22_2(443, 309);
    Vector2f body_triangle_22_3(392, 323);
    Draw_filled_Triangle body_triangle_22(renderer, body_triangle_22_1, body_triangle_22_2, body_triangle_22_3);
    body_triangle_22.draw_trianle();

    Vector2f body_triangle_23_1(443, 309);
    Vector2f body_triangle_23_2(392, 323);
    Vector2f body_triangle_23_3(421, 302);
    Draw_filled_Triangle body_triangle_23(renderer, body_triangle_23_1, body_triangle_23_2, body_triangle_23_3);
    body_triangle_23.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_grey.r, middle_grey.g, middle_grey.b, middle_grey.a);
    Vector2f body_triangle_24_1(323, 301);
    Vector2f body_triangle_24_2(326, 262);
    Vector2f body_triangle_24_3(361, 274);
    Draw_filled_Triangle body_triangle_24(renderer, body_triangle_24_1, body_triangle_24_2, body_triangle_24_3);
    body_triangle_24.draw_trianle();

    Vector2f body_triangle_25_1(361, 274);
    Vector2f body_triangle_25_2(392, 323);
    Vector2f body_triangle_25_3(421, 302);
    Draw_filled_Triangle body_triangle_25(renderer, body_triangle_25_1, body_triangle_25_2, body_triangle_25_3);
    body_triangle_25.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_grey.r, light_grey.g, light_grey.b, light_grey.a);
    Vector2f body_triangle_26_3(361, 274);
    Vector2f body_triangle_26_1(323, 301);
    Vector2f body_triangle_26_2(392, 323);
    Draw_filled_Triangle body_triangle_26(renderer, body_triangle_26_1, body_triangle_26_2, body_triangle_26_3);
    body_triangle_26.draw_trianle();

    //Body(white)
    SDL_SetRenderDrawColor(renderer, dark_white.r, dark_white.g, dark_white.b, dark_white.a);
    Vector2f body_triangle_27_1(326, 262);
    Vector2f body_triangle_27_2(361, 274);
    Vector2f body_triangle_27_3(361, 251);
    Draw_filled_Triangle body_triangle_27(renderer, body_triangle_27_1, body_triangle_27_2, body_triangle_27_3);
    body_triangle_27.draw_trianle();

    Vector2f body_triangle_28_1(361, 274);
    Vector2f body_triangle_28_2(421, 302);
    Vector2f body_triangle_28_3(425, 264);
    Draw_filled_Triangle body_triangle_28(renderer, body_triangle_28_1, body_triangle_28_2, body_triangle_28_3);
    body_triangle_28.draw_trianle();

    Vector2f body_triangle_29_1(443, 309);
    Vector2f body_triangle_29_2(421, 302);
    Vector2f body_triangle_29_3(425, 264);
    Draw_filled_Triangle body_triangle_29(renderer, body_triangle_29_1, body_triangle_29_2, body_triangle_29_3);
    body_triangle_29.draw_trianle();

    Vector2f body_triangle_30_1(443, 309);
    Vector2f body_triangle_30_2(479, 326);
    Vector2f body_triangle_30_3(469, 269);
    Draw_filled_Triangle body_triangle_30(renderer, body_triangle_30_1, body_triangle_30_2, body_triangle_30_3);
    body_triangle_30.draw_trianle();

    Vector2f body_triangle_31_1(479, 326);
    Vector2f body_triangle_31_2(502, 288);
    Vector2f body_triangle_31_3(513, 321);
    Draw_filled_Triangle body_triangle_31(renderer, body_triangle_31_1, body_triangle_31_2, body_triangle_31_3);
    body_triangle_31.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_white.r, middle_white.g, middle_white.b, middle_white.a);
    Vector2f body_triangle_32_1(326, 262);
    Vector2f body_triangle_32_3(361, 251);
    Vector2f body_triangle_32_2(340, 210);
    Draw_filled_Triangle body_triangle_32(renderer, body_triangle_32_1, body_triangle_32_2, body_triangle_32_3);
    body_triangle_32.draw_trianle();

    Vector2f body_triangle_33_1(361, 251);
    Vector2f body_triangle_33_2(361, 274);
    Vector2f body_triangle_33_3(425, 264);
    Draw_filled_Triangle body_triangle_33(renderer, body_triangle_33_1, body_triangle_33_2, body_triangle_33_3);
    body_triangle_33.draw_trianle();

    Vector2f body_triangle_34_1(425, 264);
    Vector2f body_triangle_34_2(469, 269);
    Vector2f body_triangle_34_3(443, 309);
    Draw_filled_Triangle body_triangle_34(renderer, body_triangle_34_1, body_triangle_34_2, body_triangle_34_3);
    body_triangle_34.draw_trianle();

    /**
     * Body Finsihed
    **/ 

    //Whale's Tail
    SDL_SetRenderDrawColor(renderer, middle_grey.r, middle_grey.g, middle_grey.b, middle_grey.a);
    Vector2f tail_triangle_1_1(534, 386);
    Vector2f tail_triangle_1_2(554, 386);
    Vector2f tail_triangle_1_3(610, 438);
    Draw_filled_Triangle tail_triangle_1(renderer, tail_triangle_1_1, tail_triangle_1_2, tail_triangle_1_3);
    tail_triangle_1.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_grey.r, dark_grey.g, dark_grey.b, dark_grey.a);
    Vector2f tail_triangle_2_1(554, 386);
    Vector2f tail_triangle_2_2(610, 438);
    Vector2f tail_triangle_2_3(654, 409);
    Draw_filled_Triangle tail_triangle_2(renderer, tail_triangle_2_1, tail_triangle_2_2, tail_triangle_2_3);
    tail_triangle_2.draw_trianle();

    Vector2f tail_triangle_3_1(534, 386);
    Vector2f tail_triangle_3_2(610, 438);
    Vector2f tail_triangle_3_3(551, 415);
    Draw_filled_Triangle tail_triangle_3(renderer, tail_triangle_3_1, tail_triangle_3_2, tail_triangle_3_3);
    tail_triangle_3.draw_trianle();

    SDL_SetRenderDrawColor(renderer, light_black.r, light_black.g, light_black.b, light_black.a);
    Vector2f tail_triangle_4_1(610, 438);
    Vector2f tail_triangle_4_2(551, 415);
    Vector2f tail_triangle_4_3(600, 460);
    Draw_filled_Triangle tail_triangle_4(renderer, tail_triangle_4_1, tail_triangle_4_2, tail_triangle_4_3);
    tail_triangle_4.draw_trianle();

    Vector2f tail_triangle_5_1(551, 415);
    Vector2f tail_triangle_5_2(600, 460);
    Vector2f tail_triangle_5_3(527, 481);
    Draw_filled_Triangle tail_triangle_5(renderer, tail_triangle_5_1, tail_triangle_5_2, tail_triangle_5_3);
    tail_triangle_5.draw_trianle();

    SDL_SetRenderDrawColor(renderer, middle_black.r, middle_black.g, middle_black.b, middle_black.a);
    Vector2f tail_triangle_6_1(551, 415);
    Vector2f tail_triangle_6_2(522, 453);
    Vector2f tail_triangle_6_3(527, 481);
    Draw_filled_Triangle tail_triangle_6(renderer, tail_triangle_6_1, tail_triangle_6_2, tail_triangle_6_3);
    tail_triangle_6.draw_trianle();

    Vector2f tail_triangle_7_1(610, 438);
    Vector2f tail_triangle_7_2(654, 409);
    Vector2f tail_triangle_7_3(727, 409);
    Draw_filled_Triangle tail_triangle_7(renderer, tail_triangle_7_1, tail_triangle_7_2, tail_triangle_7_3);
    tail_triangle_7.draw_trianle();

    Vector2f tail_triangle_8_1(654, 409);
    Vector2f tail_triangle_8_2(727, 409);
    Vector2f tail_triangle_8_3(554, 386);
    Draw_filled_Triangle tail_triangle_8(renderer, tail_triangle_8_1, tail_triangle_8_2, tail_triangle_8_3);
    tail_triangle_8.draw_trianle();

    SDL_SetRenderDrawColor(renderer, dark_black.r, dark_black.g, dark_black.b, dark_black.a);
    Vector2f tail_triangle_9_1(554, 386);
    Vector2f tail_triangle_9_2(609, 390);
    Vector2f tail_triangle_9_3(593, 382);
    Draw_filled_Triangle tail_triangle_9(renderer, tail_triangle_9_1, tail_triangle_9_2, tail_triangle_9_3);
    tail_triangle_9.draw_trianle();

    Vector2f tail_triangle_10_1(609, 390);
    Vector2f tail_triangle_10_2(593, 382);
    Vector2f tail_triangle_10_3(627, 388);
    Draw_filled_Triangle tail_triangle_10(renderer, tail_triangle_10_1, tail_triangle_10_2, tail_triangle_10_3);
    tail_triangle_10.draw_trianle();

    Vector2f tail_triangle_11_1(554, 386);
    Vector2f tail_triangle_11_2(727, 409);
    Vector2f tail_triangle_11_3(680, 388);
    Draw_filled_Triangle tail_triangle_11(renderer, tail_triangle_11_1, tail_triangle_11_2, tail_triangle_11_3);
    tail_triangle_11.draw_trianle();
    /**
     * Tail Finished
    **/
    

    //Bubble
    SDL_Point center_small = {218, 97};
    Draw_filled_circle circle_small(center_small, renderer, 16, blue);
    circle_small.draw_circle();

    SDL_Point center_middle = {245, 55};
    Draw_filled_circle circle_middle(center_middle, renderer, 21, blue);
    circle_middle.draw_circle();

    SDL_Point center_large = {296, 28};
    Draw_filled_circle circle_large(center_large, renderer, 26, blue);
    circle_large.draw_circle();
}