#!/bin/bash
# ==========================================
# SYSTEM ZERO - Linux Optimization Tool v1.0
# Author: DavidEngineer (ortiz10m)
# Goal: Max Performance for Low-Spec PCs
# ==========================================

# 1. Colores para que se vea Hacker (Estética Terminal)
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 2. Verificar si somos ROOT (Si no, no funciona)
if [ "$EUID" -ne 0 ]; then
  echo -e "${RED}[ERROR] Por favor, ejecuta esto como root (sudo).${NC}"
  exit
fi

clear
echo -e "${BLUE}=======================================${NC}"
echo -e "${GREEN}      SYSTEM ZERO - ONLINE 🟢          ${NC}"
echo -e "${BLUE}=======================================${NC}"
echo "Iniciando protocolos de optimización..."
sleep 1

# 3. Función: Limpiar Caché de RAM (Lo más importante para ti)
echo -e "\n${BLUE}[1/3] Liberando Memoria RAM...${NC}"
# 'sync' asegura que los datos se guarden antes de borrar
sync 
# Este comando le dice al Kernel que suelte la memoria caché inútil
echo 3 > /proc/sys/vm/drop_caches
echo -e "${GREEN}Done! RAM Liberada.${NC}"
sleep 1

# 4. Función: Limpiar Paquetes Basura (APT)
echo -e "\n${BLUE}[2/3] Limpiando archivos basura de instalaciones...${NC}"
apt-get autoremove -y  # Borra dependencias huérfanas
apt-get clean          # Borra instaladores viejos (.deb) del caché
echo -e "${GREEN}Done! Basura eliminada.${NC}"
sleep 1

# 5. Función: Actualizar Repositorios (Opcional, pero bueno)
echo -e "\n${BLUE}[3/3] Actualizando listas de paquetes...${NC}"
apt-get update
echo -e "${GREEN}Done! Listas al día.${NC}"

echo -e "\n${BLUE}=======================================${NC}"
echo -e "${GREEN}   OPTIMIZACIÓN COMPLETADA CON ÉXITO   ${NC}"
echo -e "${BLUE}=======================================${NC}"
