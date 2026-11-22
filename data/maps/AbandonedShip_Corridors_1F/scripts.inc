AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Ủa cầm phao chạy vòng vòng\n"
	.string "tàu thì có gì mắc cười?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Trời, dữ quá!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Không dễ chọi CẦU POKéMON\n"
	.string "khi đang đeo phao đâu!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Ở đây vui mà?\n"
	.string "Tui rất khoái chỗ này!$"
