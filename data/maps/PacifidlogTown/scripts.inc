PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Vùng biển giữa LÀNG NỔI và TP.CẢNG\n"
    .string "có dòng thủy triều chảy rất mạnh.\p"
    .string "Nếu bạn LƯỚT SÓNG qua đó, bạn có thể\n"
    .string "bị cuốn trôi đến một nơi khác.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Thấy hay không?\n"
	.string "Nhà trôi lềnh bềnh trên mặt nước luôn!\p"
	.string "Tui được sanh ra ở đây nè!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "CỘT TRỜI hả?\p"
	.string "…Ạaàa, ý bạn là cái toà tháp cao,\n"
	.string "cao ở ngoài kia, hơi xa một chút.\p"
	.string "Nếu bạn có hỏi, tui không dám leo lên đâu.\n"
	.string "Leo lên đó cao quá, tui sợ.\p"
	.string "Cuộc sống trên biển ở LÀNG NỔI,\n"
	.string "hợp với tui hơn.$"

PacifidlogTown_Text_TownSign:
	.string "LÀNG NỔI\p"
	.string "“Nơi mà mặt trời mỉm cười\n"
	.string "với mặt nước.”$"

