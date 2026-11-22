VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "QUÝ: {PLAYER}, tui thua bạn, nhưng\n"
	.string "mà tui không thấy buồn nữa.\p"
	.string "Bởi vì tui có mục đích sống rồi.\n"
	.string "Cùng với RALTS, tui sẽ\l"
	.string "thách đấu NHÀ THI ĐẤU POKéMON\l"
	.string "và trở thành NHL tài giỏi.\p"
	.string "Nên là hãy dõi theo tui, {PLAYER} ơi.\n"
	.string "Tui sẽ mạnh hơn bạn cho coi.\p"
	.string "Tới lúc đó, tui muốn\n"
	.string "thách đấu bạn một trận.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "QUÝ: Hãy dõi theo tui, {PLAYER}.\n"
	.string "Tui sẽ mạnh hơn bạn cho coi.\p"
	.string "Tới lúc đó, tui muốn\n"
	.string "thách đấu bạn một trận.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "CHÚ: Ủa! {PLAYER}!\n"
	.string "Bạn của QUÝ.\p"
	.string "Nhưng mà con ơi, chú có\n"
	.string "cái này muốn nói.\p"
	.string "Môi trường tự nhiên ở đây\n"
	.string "đã giúp ích rất nhiều cho QUÝ.\p"
	.string "Có lẽ không chỉ môi trường.\n"
	.string "Có thể là POKéMON đang tiếp sức\l"
	.string "cho thằng bé.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "QUÝ đi mất tiêu rồi…\n"
	.string "Nó chạy đi đâu mất tiêu nữa rồi…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "CHÚ: Thiệt hả?\n"
	.string "QUÝ nó tự đi xa\l"
	.string "một mình…\p"
	.string "Vậy chắc chú phải chiều nó thôi--dẫu sao\n"
	.string "nó cũng là con của em chú.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "QUỲNH: Bạn là?\n"
	.string "À, biết rồi!\p"
	.string "Bạn là {PLAYER} mà QUÝ\n"
	.string "kể cho tui nghe.\p"
	.string "Tui là chị họ của QUÝ.\n"
	.string "Hân hạnh được làm quen!\p"
	.string "Tui thấy QUÝ bắt đầu khoẻ mạnh\n"
	.string "và yêu đời hơn từ lúc tới đây.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "QUỲNH: Đừng có lo về QUÝ.\n"
	.string "Nó sẽ ổn thôi.\p"
	.string "Tui biết tánh em tui mà, với lại\n"
	.string "nó cũng có POKéMON ở chung nữa mà.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Nhờ bạn mà tui được\n"
	.string "gặp người thương mỗi ngày.\l"
	.string "Vui không? Có chứ!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Bạn trai của con gái dì là một người\n"
    .string "rất quyết tâm và đầy nhiệt huyết.\p"
    .string "Nó đã đào cái đường hầm không ngừng\n"
    .string "nghỉ chỉ để được gặp con gái dì.\p"
    .string "Con gái dì cũng hơi lo, nên lâu lâu\n"
	.string "con bé hay ra đường hầm đó để coi.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Giỏi ghê. Bạn trai của con gái dì\n"
	.string "tự tay đào cái hầm đó!\p"
	.string "Thật đáng ngưỡng mộ!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Nếu có chuyện gì với QUÝ,\n"
	.string "dì sẽ không dám nhìn vô\l"
	.string "mắt cha mẹ nó ở HOA CAM quá…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "QUÝ đang ở SẮC MÀU hả?\p"
	.string "Cha mẹ nó ở HOA CAM chắc cũng\n"
	.string "phải bật ngửa khi nghe tin!$"

