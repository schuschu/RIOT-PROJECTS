# Name of your application
APPLICATION = boiler-room-controller

# If no BOARD is found in the environment, use this default:
#BOARD ?= native
#BOARD ?= lctech-stm32f103c8t6
BOARD ?= sens-core-v0_1

# This has to be the absolute path to the RIOT base directory:
RIOTBASE  ?= $(CURDIR)/../../../RIOT

# Boards that is not in RIOT tree
RIOTBOARD ?= $(CURDIR)/../../boards

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
CFLAGS += -DDEVELHELP

# FIXME: Decide the right place to add definition. I think the proper place is
# in board descriptions files. See cpu/stm32f1/include/stm32f10x.h file.
CFLAGS += -DSTM32F10X_MD

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

# Modules to include:
#USEMODULE += xtimer

 USEMODULE += enc28j60
USEMODULE += gnrc_netdev2
 USEMODULE += gnrc_netif_default
USEMODULE += auto_init_gnrc_netif
 USEMODULE += gnrc_ipv6
#USEMODULE += gnrc_ndp
 USEMODULE += gnrc_icmpv6_echo

USEMODULE += dht
# Use DHT driver with external pullup resistor on data pin
CFLAGS += -DDHT_EXT_PULLUP

# Specify custom includes for your application here ...
#export INCLUDES += -Iapplication_include


################################################################################
## RIOT-EXTRAS

X_RIOTBASE ?= $(CURDIR)/../..

X_USEMODULE += example_service_1
#X_USEMODULE += pressure_monitor

include $(X_RIOTBASE)/Makefile.include
################################################################################


# Specify custom dependencies for your application here ...
# APPDEPS = app_data.h config.h

include $(RIOTBASE)/Makefile.include

# ... and define them here (after including Makefile.include,
# otherwise you modify the standard target):
#proj_data.h: script.py data.tar.gz
#	./script.py
