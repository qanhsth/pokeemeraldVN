OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Khi POKéMON chiến đấu, chúng sẽ\n"
	.string "từ từ thăng cấp và trở nên mạnh hơn.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Nếu mà POKéMON của bạn mạnh hơn,\n"
	.string "bạn sẽ được đi xa hơn nữa, chứ\l"
	.string "không phải chỉ ở đây thôi đâu.$"

