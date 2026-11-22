MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hừm!\n"
	.string "{STR_VAR_1} của bạn…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Nó có thích {STR_VAR_1} mà,\n"
	.string "đúng không?\p"
	.string "Thích chắc luôn! Chắc chắn\n"
	.string "là nó có thích {STR_VAR_1}!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Hình như nó không thích\n"
	.string "cũng không ghét {POKEBLOCK}.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Chồng tui chỉ cần nhìn là biết\n"
	.string "POKéMON thích loại {POKEBLOCK} nào luôn.$"

