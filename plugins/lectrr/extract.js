function(page) {
    var regex = /<img src="(.+?jpg)\?.+?alt="Cartoon\svan\sde\sdag/;
    var match = regex.exec(page);
    return match[1];
}
