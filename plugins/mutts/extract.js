function(page) {
    var regex = /"(https:\/\/mutts.com\/wp-content\/uploads\/20[^"]*.gif)"/;
    var match = regex.exec(page);
    return match[1];
}
