SECTIONS
{
    .init_array >       L2SRAM
    .sharedGRL: load >> L2SRAM
    .sharedPolicy: load >> L2SRAM
    .rm: load >> MSMCSRAM      
}
