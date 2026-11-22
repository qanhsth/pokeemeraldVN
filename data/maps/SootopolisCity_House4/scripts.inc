SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Nói nghe, để tui kể cho bạn\n"
	.string "nghe cái này.\p"
	.string "Lẽ ra phải có tàn tích cổ đại\n"
	.string "dưới biển ở vòng vòng khu này.\p"
	.string "Cũng có thể có kho báu đang chờ\n"
	.string "người tới khai quật ở dưới đó.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Kho báu cổ đại…\p"
	.string "Nếu mà có thì hay, nhưng mà\n"
	.string "kể cả không có đi nữa, thì cũng\l"
	.string "thật đẹp khi được đi dạo dưới\l"
	.string "biển cùng với POKéMON của mình.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Mà rư rii.$"

