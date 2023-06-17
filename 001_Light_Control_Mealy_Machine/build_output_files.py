Import("env")

# Costom HEX from ELF
env.AddPostAction(
    "$BULD_DIR/${PROGNAME}.elf",
    env.VerboseAction(" ".join([
        "$OBJCOPY", "-O", "ihex", "-R", ".eeprom",
        "$BULD_DIR/${PROGNAME}.elf", "$BULD_DIR/${PROGNAME}.hex"
    ]), "Building $BULD_DIR/${PROGNAME}.hex")
)