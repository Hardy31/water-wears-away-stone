void init_world(char** field) {
    clear_field(field);

    char** figure;

    figure = get_frog();
    add_figure(field, figure, 14, 13);
    free(figure);

    figure = get_spaceshipL();
    add_figure(field, figure, 20, 19);
    free(figure);

    figure = get_glider();
    add_figure(field, figure, 6, 6);
    free(figure);

    figure = get_house();
    add_figure(field, figure, WIDTH / 2, HEIGHT / 2);
    free(figure);

    figure = get_five();
    add_figure(field, figure, WIDTH-6, HEIGHT-6);
    free(figure);
    
}