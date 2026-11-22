LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Vợ ta ngâm TRỨNG trong suối\n"
	.string "nước nóng. Cổ nói với ta vậy đó.\p"
	.string "Cổ để lại 2 POKéMON cho người CHĂM.\n"
	.string "Rồi người ta phát hiện ra cái TRỨNG đó!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: Hắt xì!$"

