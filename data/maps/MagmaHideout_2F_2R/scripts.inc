MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
    .string "Ta không muốn cản đường ngươi đâu.\n"
    .string "Ta chỉ đang làm theo lệnh thôi!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
    .string "Ta có thể thua, nhưng…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
    .string "Tụi ta đã đào được một thứ không tưởng!\n"
    .string "Và, tụi ta đã có được NGỌC XANH!\p"
    .string "Giờ chỉ còn chờ thủ lĩnh…\n"
    .string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Ta không chịu nóng được. Lẽ ra\n"
	.string "ta nên gia nhập ĐỘI AQUA mới phải…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ừ, chắc là ta không hợp\n"
	.string "ĐỘI MAGMA rồi…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Ngươi có cảm thấy tội nghiệp biển\n"
	.string "vì bản thân đang ở nơi đây không?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "Lâu lâu ở đây có tiếng rung lắc.\p"
    .string "Không lẽ núi lửa đang rung chuyển?\n"
	.string "Hay là tại GROU…\p"
	.string "Ủa!\n"
	.string "Không, không, không có gì đâu!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
    .string "Ngươi là một người đầy nhiệt huyết.\n"
    .string "Cứ như núi lửa vậy!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
    .string "Lần này ngươi chỉ tình cờ thắng thôi,\n"
    .string "nhưng điều đó không quan trọng.\p"
    .string "Mục tiêu của ĐỘI MAGMA sắp\n"
    .string "đạt được rồi!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Có thằng nó sợ làm mất\n"
	.string "HUY HIỆU MAGMA của nó…\p"
	.string "Mà khoan!\n"
	.string "Ngươi kiếm được rồi hả?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Ta không tin tưởng vụ này cho lắm…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Ta có cảm giác kế hoạch của tụi ta\n"
	.string "sẽ thất bại mà thôi…$"

