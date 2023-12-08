.PHONY: clean All

All:
	@echo "----------Building project:[ PECLDuqueReyTian - Debug ]----------"
	@cd "PL1_EEDD_GestionAmazon_2023_24" && "$(MAKE)" -f  "PECLDuqueReyTian.mk"
clean:
	@echo "----------Cleaning project:[ PECLDuqueReyTian - Debug ]----------"
	@cd "PL1_EEDD_GestionAmazon_2023_24" && "$(MAKE)" -f  "PECLDuqueReyTian.mk" clean
