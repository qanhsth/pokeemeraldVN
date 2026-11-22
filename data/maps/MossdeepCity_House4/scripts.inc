MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "Thằng em tui kêu là nó muốn\n"
	.string "đi kiếm CĂN CỨ BÍ MẬT của người ta.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "Thằng em tui kêu là nó muốn\n"
	.string "thích ghé qua CĂN CỨ BÍ MẬT rồi thách\l"
	.string "đấu với POKéMON của người ta luôn.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Ủa bạn làm CĂN CỨ BÍ MẬT\n"
	.string "gần chỗ {STR_VAR_1} hả?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "Bạn nên làm CĂN CỨ ở chỗ\n"
	.string "khác đi. Để tui đi kiếm!$"

MossdeepCity_House4_Text_Skitty:
	.string "SKITTY: Meooéoo?$"

