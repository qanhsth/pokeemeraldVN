DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Có nhiều cái để nói về cuộc sống\n"
	.string "trên hòn đảo nhỏ này, chung sống cùng\l"
	.string "POKéMON và gia đình.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Dì đã đi khỏi cái cảng lớn ở\n"
	.string "TP.CẢNG từ hồi lấy chồng.\p"
	.string "Sống chậm hơn xíu nhưng mà được cái\n"
	.string "xung quanh là bờ biển đẹp,\l"
	.string "nói chung cũng thoả mãn rồi.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gừ gứưư!$"

