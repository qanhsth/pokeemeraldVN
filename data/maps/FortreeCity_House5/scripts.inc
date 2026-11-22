FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Nhà ở TP.CÂY rất tốt!\p"
	.string "Thiết nghĩ đây là nơi lý tưởng\n"
	.string "nhất để chung sống với POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "POKéMON và con người đã thích nghi\n"
    .string "với thiên nhiên để sinh tồn.\p"
    .string "Không cần phải ép thiên nhiên phải\n"
    .string "tuân theo cách mà chúng ta muốn.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: Bừ hưưư!$"

