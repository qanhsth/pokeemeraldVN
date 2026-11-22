FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Nói thì không ai tin chứ tui\n"
	.string "thấy POKéMON to lớn trên bầu trời.\p"
	.string "Hình như nó đang lượn lờ\n"
	.string "ở ĐƯỜNG 131.\p"
	.string "À mà… Hửi hửi…\n"
	.string "Ừm… Bạn, ờ…có mùi khét khét.\p"
	.string "Mới ở trên núi lửa xuống hả?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Tui muốn lại NHÀ THI ĐẤU,\n"
	.string "mà có cái gì đó cản đường rồi.\p"
	.string "Đi lòng vòng một hồi, tui quyết\n"
	.string "định luyện tập ở ĐƯỜNG 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Tui đã đem POKéMON yêu quý theo mình.\n"
	.string "Lần này, tui sẽ hạ gục QUỲNH NHƯ.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Nước mưa thấm vô đất, rồi mấy cái\n"
	.string "cây tự hút lên nuôi lớn mình…\p"
	.string "TP.CÂY của tụi tui tồn tại là bởi\n"
	.string "nơi đây vừa có nước vừa có đất.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "THÀNH PHỐ này toàn là\n"
	.string "nhà ở trên cây.\p"
	.string "Có lẽ bởi đời sống như vậy, người\n"
	.string "ta rất khoẻ mạnh và đầy sức sống.\p"
	.string "Kể cả bản thân ta--cảm giác như\n"
	.string "mình trẻ lại 30 tuổi đời.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Sống trên cây cũng được.\p"
	.string "Mà lâu lâu mấy con POKéMON BỌ\n"
	.string "cứ bay ngang cửa sổ.\l"
	.string "Làm tui giựt mình.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Có loại POKéMON chỉ tiến hoá khi\n"
	.string "trao đổi! Tui nghe nói vậy đó.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Có gì đó vô hình đang cản đường.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Có gì đó vô hình đang cản đường.\p"
	.string "Xài MÁY DÒ DEVON không?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} xài MÁY DÒ DEVON.\p"
	.string "Một con POKéMON vô hình tự nhiên\n"
    .string "hiện rõ ra!\p"
    .string "POKéMON hốt hoảng bỏ chạy!$"

FortreeCity_Text_CitySign:
	.string "TP.CÂY\n"
	.string "“Nơi con người vui đùa\l"
	.string "với thiên nhiên, cây cối.”$"

FortreeCity_Text_GymSign:
	.string "NHÀ THI ĐẤU TP.CÂY\n"
	.string "CHỦ: QUỲNH NHƯ\p"
	.string "“Người thích bay lượn vòng\n"
	.string "quanh thế giới với chim.”$"

