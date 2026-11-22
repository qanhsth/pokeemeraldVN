MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Thầy ơi…\n"
	.string "Xin hãy coi sự tiến bộ của em!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Thầy ơi…\n"
	.string "Mong thầy thứ lỗi!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Cho tới khi mình tiến bộ, thầy tui,\n"
	.string "an nghỉ ở đây, sẽ không thể yên lòng…$"

