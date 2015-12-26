#ifneq (,$(filter example_service_1,$(USESERVICE)))
#    DIRS += example_service_1
#endif

DIRS += $(dir $(wildcard $(addsuffix /Makefile, ${USESERVICE})))

include $(RIOTBASE)/Makefile.base
