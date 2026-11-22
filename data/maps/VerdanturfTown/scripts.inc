VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Ba tui có nói với tui.\p"
	.string "Ổng nói đường hầm này toàn\n"
	.string "POKéMON nhạy cảm không à.\p"
	.string "Tụi nó rất sợ tiếng ồn lớn\n"
	.string "và hay gây ra náo loạn.\p"
	.string "Bởi vậy người ta mới phải\n"
	.string "ngừng dự án đường hầm.\p"
	.string "Mà có 1 người. Ổng đang tự mình\n"
	.string "đào hết cái đường hầm này luôn!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Có 1 anh trai đào hầm để\n"
	.string "tới được chỗ của người thương.\p"
	.string "Tui cũng không hiểu lắm, mà ý là!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Với hướng gió thổi, tro núi lửa\n"
    .string "chưa bao giờ bị thổi về hướng này.\p"
    .string "Không khí ở đây trong lành và dễ chịu.\n"
    .string "Sống ở đây sẽ nhận được những điều kỳ\l"
    .string "diệu kể cả những người yếu ớt và ốm yếu.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "POKéMON với tui, tụi tui đang\n"
	.string "giành chiến thắng liên tục.\p"
	.string "Nên tui quyết định tham gia\n"
	.string "HỘI THI ĐẤU ở thị trấn này.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Bạn có thấy cái hang kế\n"
	.string "SIÊU THỊ không?\p"
	.string "Có một người ở trong đó đang cố gắng\n"
    .string "đập bể những tảng đá lớn để có thể\l"
    .string "đi qua bên kia.\p"
    .string "Nếu đi được qua bên kia thì hay biết mấy…\n"
    .string "Như vậy sẽ dễ hơn ghé qua KIM THÁN hơn.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Cái hang kế SIÊU THỊ giờ là\n"
	.string "đường hầm để đi qua bên kia.\p"
	.string "Hay quá--giờ thì mình có thể\n"
	.string "qua KIM THÁN mua đồ DEVON rồi.$"

VerdanturfTown_Text_TownSign:
	.string "THỊ TRẤN GIẢN ĐƠN\p"
	.string "“Cao nguyên hiu quạnh, có gió thổi qua\n"
    .string "cùng với hương thơm ngọt ngào của cỏ.”$"

VerdanturfTown_Text_WandasHouse:
	.string "NHÀ CỦA QUỲNH$"

VerdanturfTown_Text_BattleTentSign:
	.string "HỘI THI ĐẤU GIẢN ĐƠN\n"
	.string "“Những trận đấu Đã Con Mắt!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "ĐƯỜNG HẦM KIM CHI\n"
	.string "“Nối giữa KIM THÁN và GIẢN ĐƠN\p"
	.string "“Dự án đường hầm\n"
	.string "đang bị tạm ngưng.”$"

