# Name of your application
APPLICATION = example-project-1

# If no BOARD is found in the environment, use this default:
BOARD ?= native
#BOARD ?= lctech-stm32f103c8t6

# This has to be the absolute path to the RIOT base directory:
RIOTBASE  ?= $(CURDIR)/../../../RIOT

# Boards that is not in RIOT tree
#RIOTBOARD ?= $(CURDIR)/../../boards/

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#CFLAGS += -DDEVELHELP

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

# Modules to include:
#USEMODULE += XXX

# Specify custom includes for your application here ...
#export INCLUDES += -Iapplication_include


################################################################################
## RIOT-EXTRAS

X_RIOTBASE ?= $(CURDIR)/../..

X_USEMODULE += example_service_1
#X_USEMODULE += example_service_2

include $(X_RIOTBASE)/Makefile.include
################################################################################


# Specify custom dependencies for your application here ...
# APPDEPS = app_data.h config.h

include $(RIOTBASE)/Makefile.include

# ... and define them here (after including Makefile.include,
# otherwise you modify the standard target):
#proj_data.h: script.py data.tar.gz
#	./script.py
