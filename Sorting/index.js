#!/usr/bin/env node

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
  figlet.text(
    msg,
    {
      horizontalLayout: "default",
      verticalLayout: "default",
      width: 80,
      whitespaceBreak: false,
    },
    function (err, data) {
      if (err) {
        console.log("Something went wrong...");
        console.dir(err);
        return;
      }
      console.log(gradient.pastel.multiline(data));
    }
  );
};

//! SORTING ELEMENTS
const bubbleSort = (arr, order) => {
  let i, j;
  let conditions;
  if (!arr.length) return;

  for (i = 0; i < arr.length; i++) {
    for (j = 0; j < arr.length - i - 1; j++) {
      //* DINAMIC CONDITIONS CHACKING
      switch (order) {
        case "Ascending ":
          conditions = arr[j + 1] < arr[j];
          break;
        case "Descending":
          conditions = arr[j + 1] > arr[j];
          break;
      }
      if (conditions) {
        [arr[j + 1], arr[j]] = [arr[j], arr[j + 1]];
      }
    }
  }
  animateArray(arr);
};
//? ASK INPUT DATA AND RETURN IN MAIN FUNCTION
const askArray = async () => {
  const elements = await inquirer.prompt({
    name: "array",
    type: "input",
    message: `Enter ${chalk.bgBlack(chalk.white("Number or String"))}
    What your ${chalk.bgGray(chalk.white("Array Elements"))}`,
    default() {
      return 54321;
    },
  });
  const order = await inquirer.prompt({
    name: "order",
    type: "list",
    choices: ["Ascending ", "Descending"],
    message: `Choice your ${chalk.bgBlack(
      chalk.white("Number or String order")
    )}`,
  });
  bubbleSort(Array.from(elements.array.toString()), order.order);
};
await askArray();
