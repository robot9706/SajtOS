ELF                      t      4     (   U��WV1�S���   �� F��u���u!h    hB   h$  hK   ���������  hg   �    hB   ��    h(  hK   ������L   �\wZY��R�    ��Ph�   hB   h.  hK   �������Sh�   hB   h4  hK   �������1�j�   jh   R1�S�����������uPPh�   j��������  ��Ph�   hB   h?  hK   ��������� �    �������߃�W�   h  hB   hG  hK   �}�1��U�������E�� �U܊J����M�J�H��Q�M�E؉U�QWGh>  hB   hM  hK   ������E؃� �U܃�9��|��M���   Oƃ����A� �B PhV  hB   hR  hK   ��������ÉL   ��PShp  hB   hW  hK   ������� 1��e�[^_]�U��WV��S�Ã�1��;(��Ê<h��t<fu5�{du/��1ɉ�1ҍC�����������w�=     u1���t	���VSh�  j��������e�[^_]�U����    ��tD�L   �   ������L   �        RR��R��Ph�  hB   hf  hK   ������� 1���U��WVS���=    u��h�  ��������Z��h  ������   ���>�S�   ���C!����ȃ���W��fR����Q��V��FPh5  �������� ��u��e�1�[^_]�U��S�Ã��   �8Xt� ��u��2�P�&PPhU  j���������P�   �X�   �1��]��ø   �U�������U��u��U��WV��S�Ã��@�8 u2�x t%�   �	�������؅�u��       1��.  ��Hu
������  ���E� �E��tQQh�  j�����������   ��U������������   �F�U�����������   �E�U�8�uYR��RP�6h�  hB   h�   hK   ������M�� �   1��	8Ht� ��u��   �ҋt�
��   ������l�{�ȸ�  �҃ ��  Dǃ�R�6Q�vPh�  hB   h�   hK   ������U��0�E��K�������u�C�x t�U��E��/����Ǎe��[^_]�U��SP��  �������t[1�[1�]�����1�����������t4���t4�Q��t-�z u'�   �Y��J9�u�Z����u����[[]��������U1ɉ���    h    ��  h�  h  �    �B   �    8  �������  �|  �   X�    ������   ��U1���]�U����    �    �   ������   �       ������U��]�ː�R�PS�H .�8�tCC8�u��[X��t��t��.�C U��Z�V]Zϝ�.�C U��V��    �    +  l       0          K  r       Q          {  s       �                                  No drives marked as remapped, not installing our int13h handler.
 drivemap commands/i386/pc/drivemap.c Installing our int13h handler
 Original int13 handler: %04x:%04x
 Payload is %u bytes long
 couldn't reserve memory for the int13h handler Reserved memory at %p, copying handler
 Target map at %p, copying mappings
 	#%d: 0x%02x <- 0x%02x
 	#%d: 0x00 <- 0x00 (end)
 New int13 handler: %04x:%04x
 device format "%s" invalid: must be (f|h)dN, with 0 <= N < 128 Restored int13 handler: %04x:%04x
 No drives have been remapped
 OS disk #num ------> GRUB/BIOS device
 %cD #%-3u (0x%02x)       %cd%d
 cannot allocate map entry, not enough memory Swapping Mapping two arguments required Removing mapping for %s (%02x)
 %s %s (%02x) = %s (%02x)
 biosnum Manage the BIOS drive mappings. -l | -r | [-s] grubdev osdisk. list Show the current mappings. reset Reset all mappings to the default values. swap Perform both direct and reverse mappings.   LICENSE=GPLv3+  boot extcmd mmap drivemap  .symtab .strtab .shstrtab .rel.text .rel.rodata .rodata.str1.1 .data .module_license .bss .note.GNU-stack .moddeps .modname                                                       4   �                    	           �  �              )             �  `                  %   	           �  0               1      2          �                @             �
                     F             �
                    V             �
                    [             �
                     k              �
                    t              �
  	                                �
  }                                �  0              	              �  �                                                                                            �  [        	  /                                              	              
                             *              ;              Y              p   �        �              �              �   8       �          �              �                @                     %  �        <             Z             l             ~             �             �             �             �             �              grub_mod_init grub_mod_fini grub_memmove grub_device_open grub_mmap_free_and_unregister grub_unregister_extcmd grub_drivemap_oldhandler grub_errno grub_printf grub_drivemap_fini grub_drivemap_init grub_get_root_biosnumber grub_loader_unregister_preboot_hook grub_drivemap_handler grub_malloc grub_drivemap_mapstart grub_mmap_malign_and_register grub_real_dprintf grub_device_close grub_error grub_free grub_loader_register_preboot_hook grub_register_extcmd grub_env_get grub_strtoul           #     -     2     ?     D     I     O     Y     ^     r     {     �     �     �     �     �     �     �     �     �     �     �     �     �     �                 !    &    +    5    B    r    w    �    �    �    �    �    �    �    �    �    �    C  "  P    f    m    �    �    �    �    �    �    �    �    �    �    �    �             ?    D    e    �    �    �    �    �    �    �    �    !    (    r    w    �    �    �    �    �    �    �    �    �    �    �    >    C  !  ]    z    �    �    �    �    �    �    �    �    �    �    �     �    �    �    �    �                    $    *    S  "  4                    $     0     <     