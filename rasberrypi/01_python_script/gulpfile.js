var gulp = require('gulp'),
   shell = require('gulp-shell'),
   watch = require('gulp-watch');

gulp.task('default', function () {
    return watch('script.py')
        .pipe(shell(['./update']));
});
