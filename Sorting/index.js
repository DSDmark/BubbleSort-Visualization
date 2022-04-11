import chalk from "chalk";
import chalkAnimation from "chalk-animation";
import figlet from "figlet";
import gradient from "gradient-string";
import inquirer from "inquirer";


//? ANIMATE THE TEXT OUTER ARRAY
const sleep = (ms = 2000) => new Promise((r) => setTimeout(r, ms));

const animateArray = async (array) => {
  const msg = `Your Array :-\n ${array}`;
  const rainbowTitle = chalkAnimation.rainbow(array.toString());
  await sleep();
  rainbowTitle.stop();
  //? SHOWING ARRAY IN THE FORM OF ASCII-ART
  figlet.text(msg, {
    horizontalLayout: 'default',
    verticalLayout: 'default',
    width: 80,
    whitespaceBreak: false
}, function(err, data) {
    if (err) {
        console.log('Something went wrong...');
        console.dir(err);
        return;
    }
    console.log(gradient.pastel.multiline(data));
});
}


//! SORTING ELEMENTS 
const bubbleSort = (arr) => {
  let i, j;
  if (!arr.length) return;
  for (i = 0; i < arr.length; i++) {
    for (j = 0; j < arr.length - i - 1; j++) {
      if (arr[j + 1] < arr[j]) {
        //Swapping
        [arr[j + 1], arr[j]] = [arr[j], arr[j + 1]];
      }
    }
  }
 return animateArray(arr);
};

//? ASK INPUT DATA AND RETURN IN MAIN FUNCTION
const askArray = async () => {
  const questions  = await inquirer.prompt({
    name: 'array',
    type: 'input',
    message:`What your ${chalk.bgGray(chalk.white('Array Elements'))}`,
    default() {
      return 54321;
    }
  });
  bubbleSort(Array.from(questions.array.toString())); 
}
await askArray();

