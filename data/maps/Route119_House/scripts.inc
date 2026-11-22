Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Tui nghe người ta nói là có một\n"
	.string "cái hang tên là HANG CỘI NGUỒN.\p"
	.string "Người ta đồn là linh hồn của\n"
	.string "POKéMON được tái sinh ở đó. Mà\l"
	.string "cái chuyện như vậy có thật không?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pi hoo!$"

