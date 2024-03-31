#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

void print_elf_header(Elf64_Ehdr *header)
{
	int i;

printf("Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");

printf("Class:                             %s\n", (header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
printf("Data:                              %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
printf("OS/ABI:                            ");

switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
case ELFOSABI_AIX: printf("UNIX - AIX\n"); break;
case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
case ELFOSABI_MODESTO: printf("Novell - Modesto\n"); break;
case ELFOSABI_OPENBSD: printf("UNIX - OpenBSD\n"); break;
default: printf("<unknown>\n");
}

printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
printf("Type:                              ");

switch (header->e_type)
{
case ET_NONE: printf("NONE (No file type)\n"); break;
case ET_REL: printf("REL (Relocatable file)\n"); break;
case ET_EXEC: printf("EXEC (Executable file)\n"); break;
case ET_DYN: printf("DYN (Shared object file)\n"); break;
case ET_CORE: printf("CORE (Core file)\n"); break;
default: printf("<unknown>\n");
}

printf("Entry point address:                0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return 98;
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
perror("open");
return 98;
}

if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
{
fprintf(stderr, "Error reading ELF header\n");
close(fd);
return 98;
}

if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
{
fprintf(stderr, "Not an ELF file\n");
close(fd);
return 98;
}

print_elf_header(&elf_header);

close(fd);
return 0;
}
