MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Khi tui đứng đây…\n"
	.string "Thứ sức mạnh kỳ quái chảy vô người…$"

MtPyre_6F_Text_ValerieDefeat:
    .string "Sức mạnh đang dần cạn kiệt…$"

MtPyre_6F_Text_ValeriePostBattle:
    .string "Có lẽ thứ sức mạnh này đến từ linh\n"
    .string "hồn của POKéMON chưa được an nghỉ…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… thua trận, nhưng mà…\n"
	.string "tui có năng lực…\p"
	.string "Không cần phải chạm tới\n"
	.string "BẢN ĐỒ cũng… Hì daaa!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Phía sau bạn…\n"
	.string "Là thứ gì…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Có gì đó mờ mờ…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "POKéMON an nghỉ nơi đây…\n"
	.string "Đôi khi, giỡn hớt…$"

MtPyre_6F_Text_CedricIntro:
	.string "Lạc đường hả?\n"
	.string "Không sao, có tui ở đây rồi!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Bạn thua rồi mà, ủa?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Tui có cảm giác là một NHL bị lạc\n"
    .string "lối sẽ hoảng loạn và dễ bị đánh bại.\p"
    .string "Hơi dơ, mà chắc tui không thử lại đâu…$"

