.PHONY: clean All

All:
	@echo "----------Building project:[ PECLGarciaIbanezPedro - Debug ]----------"
	@cd "PL1_EEDD_GestionAmazon_2023_24" && "$(MAKE)" -f  "PECLGarciaIbanezPedro.mk"
clean:
	@echo "----------Cleaning project:[ PECLGarciaIbanezPedro - Debug ]----------"
	@cd "PL1_EEDD_GestionAmazon_2023_24" && "$(MAKE)" -f  "PECLGarciaIbanezPedro.mk" clean
